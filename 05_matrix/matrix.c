#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

Matrix create_matrix(int r, int c)
{
    Matrix m;
    m.row = r;
    m.col = c;

    m.data = (MAT_TYPE **)malloc(r * sizeof(MAT_TYPE *));

    for (int i = 0; i < c; i++)
    {
        m.data[i] = (MAT_TYPE *)malloc(c*sizeof(MAT_TYPE));
    }
    return m;
}

void free_matrix(Matrix *m)
{
    for (int i = 0; i < m->row; i++)
    {
        free(m->data[i]);
    }

    free(m->data);
    m->data = 0;
}

void mat_add(const Matrix *A, const Matrix *B, Matrix *C)
{
    for (int i = 0; i < C->row; i++)
    {
        for (int j = 0; j < C->col; j++)
        {
            C->data[i][j] = A->data[i][j] + B->data[i][j];
        }
    }
}

void mat_dif(const Matrix *A, const Matrix *B, Matrix *C)
{
    for (int i = 0; i < C->row; i++)
    {
        for (int j = 0; j < C->col; j++)
        {
            C->data[i][j] = A->data[i][j] - B->data[i][j];
        }
    }
}

void mat_mul(const Matrix *A, const Matrix *B, Matrix *C)
{

    for (int i = 0; i < A->row; i++)
    {
        for (int j = 0; j < B->col; j++)
        {
            C->data[i][j] = 0;
            for (int k = 0; k < A->col; k++)
            {
                C->data[i][j] += A->data[i][k] * B->data[k][j];
            }
        }
    }
}

int mat_ran(const Matrix *A)
{
    MAT_TYPE z = 0;
    int rank = 0;
    Matrix copy = create_matrix(A->row, A->col);

    /*copy matrix A*/
    for (int i = 0; i < A->row; i++)
    {
        for (int j = 0; j < A->col; j++)
        {
            copy.data[i][j] = A->data[i][j];
        }
    }

    /*a big cycle*/
    for (int o = 0; o < A->col; o++)
    {
        int n = -1;
        /*check if o col is 0*/
        for (int i = o; i < A->row; i++)
        {
            if (fabs(copy.data[i][o]) > 1e-6)
            {
                n = i;
                break;
            }
        }
        /*check if o col is o exclude the first*/
        if (n == -1)
        {
            continue;
        }

        /*change the main element to the first row*/
        for (int j = 0; j < A->col; j++)
        {
            if (n == o)
            {
                break;
            }
            MAT_TYPE temp;
            temp = copy.data[o][j];
            copy.data[o][j] = copy.data[n][j];
            copy.data[n][j] = temp;
        }

        /*delete all the o col elements*/
        z = copy.data[o][o];

        for (int j = 0; j < A->col; j++)
        {
            copy.data[o][j] /= z;
        }

        for (int i = o + 1; i < A->row; i++)
        {
            z = copy.data[i][o];
            for (int j = o; j < A->col; j++)
            {
                copy.data[i][j] -= z * copy.data[o][j];
            }
        }

        rank++;
    }

    free_matrix(&copy);
    return rank;
}

int mat_inv(const Matrix *A, Matrix *B)
{
    /*create a identity matrix*/

    for (int i = 0; i < A->row; i++)
    {
        for (int j = 0; j < A->col; j++)
        {
            B->data[i][j] = 0.0;
            if (i == j)
            {
                B->data[i][j] = 1.0;
            }
        }
    }

    /*copy matrix A*/
    Matrix copy = create_matrix(A->row, A->col);

    for (int i = 0; i < copy.row; i++)
    {
        for (int j = 0; j < copy.col; j++)
        {
            copy.data[i][j] = A->data[i][j];
        }
    }

    /*Make matrix A become identity, and change matrix B with A*/

    for (int o = 0; o < copy.row; o++)
    {
        double z;
        /*check if main element is 0*/
        int n = -1;
        for (int i = o; i < A->row; i++)
        {
            if (fabs(copy.data[i][o]) > 1e-6)
            {
                n = i;
                break;
            }
        }

        if (n == -1)
        {
            free_matrix(&copy);
            return 0;
        }
        /*change the main element to the first row*/
        for (int j = 0; j < A->col; j++)
        {
            if (n == o)
            {
                break;
            }
            MAT_TYPE temp1, temp2;

            temp1 = copy.data[o][j];
            temp2 = B->data[o][j];

            copy.data[o][j] = copy.data[n][j];
            copy.data[n][j] = temp1;
            B->data[o][j] = B->data[n][j];
            B->data[n][j] = temp2;
        }

        z = copy.data[o][o];

        for (int j = 0; j < copy.col; j++)
        {
            copy.data[o][j] /= z;
            B->data[o][j] /= z;
        }

        for (int i = o + 1; i < copy.row; i++)
        {
            z = copy.data[i][o];
            for (int j = 0; j < copy.col; j++)
            {
                copy.data[i][j] -= z * copy.data[o][j];
                B->data[i][j] -= z * B->data[o][j];
            }
        }
    }

    for (int o = copy.row - 1; o > 0; o--)
    {
        double z;

        for (int i = o - 1; i >= 0; i--)
        {
            z = copy.data[i][o];
            for (int j = copy.col - 1; j >= 0; j--)
            {
                copy.data[i][j] -= z * copy.data[o][j];
                B->data[i][j] -= z * B->data[o][j];
            }
        }
    }

    free_matrix(&copy);
    return 1;
}

MAT_TYPE mat_det(const Matrix *A)
{
    int b = 0;
    MAT_TYPE m = 1;
    MAT_TYPE temp;
    MAT_TYPE det = 1;
    MAT_TYPE z = 0;

    /*copy matrix A*/
    Matrix copy = create_matrix(A->row, A->col);
    for (int i = 0; i < A->row; i++)
    {
        for (int j = 0; j < A->col; j++)
        {
            copy.data[i][j] = A->data[i][j];
        }
    }

    for (int o = 0; o < A->row - 1; o++)
    {
        /*Check if copy.data[o][o] is 0. If yes, change row*/
        if (fabs(copy.data[o][o]) < 1e-6)
        {
            int a = 0, n = 0;

            for (int i = o; i < A->row; i++)
            {
                if (fabs(copy.data[i][o]) > 1e-6)
                {
                    n = i;
                    a++;
                    break;
                }
            }

            if (a == 0)
            {
                free_matrix(&copy);
                return 0;
            }

            for (int j = 0; j < A->col; j++)
            {
                temp = copy.data[o][j];
                copy.data[o][j] = copy.data[n][j];
                copy.data[n][j] = temp;
            }

            b++;
        }

        /*delete elements*/
        z = copy.data[o][o];

        for (int j = o; j < A->col; j++)
        {
            copy.data[o][j] /= z;
        }

        m *= z;

        for (int i = o + 1; i < A->row; i++)
        {
            z = copy.data[i][o];
            for (int j = o; j < A->col; j++)
            {
                copy.data[i][j] -= z * copy.data[o][j];
            }
        }
    }

    /*Check if the last element is 0*/
    if (fabs(copy.data[A->row - 1][A->col - 1]) < 1e-6)
    {
        free_matrix(&copy);
        return 0;
    }
    else
    {
        for (int o = 0; o < A->row; o++)
        {
            det *= copy.data[o][o];
        }
    }

    m *= pow(-1, b);

    det *= m;

    free_matrix(&copy);

    return det;
}

void mat_adj(const Matrix *A,Matrix *B)
{
    /*Calculate the cofactor*/
    for(int i=0;i<A->row;i++){
        for(int j=0;j<A->col;j++){
            B->data[i][j]=mat_cof(A,i,j);
        }
    }

    /*tranpose matrix B*/
    mat_tra(B);
}

MAT_TYPE mat_cof(const Matrix *A, int m, int n)
{
    /*copy matrix A that delete its m row and n col*/
    MAT_TYPE result;
    Matrix copy = create_matrix(A->row - 1, A->col - 1);
    int i2 = 0;
    int j2 = 0;
    for (int i = 0; i < A->row; i++)
    {

        if (i == m)
        {
            continue;
        }
        for (int j = 0; j < A->col; j++)
        {

            if (j == n)
            {
                continue;
            }
            copy.data[i2][j2] = A->data[i][j];
            j2++;
        }
        i2++;
    }

    result = (MAT_TYPE)pow(-1, m + n) * mat_det(&copy);

    free_matrix(&copy);

    return result;
}

void mat_tra(Matrix *A){
    MAT_TYPE temp;

    for(int i=0;i<A->row;i++){
        for(int j=i;j<A->row;j++){
            temp=A->data[i][j];
            A->data[i][j]=A->data[j][i];
            A->data[j][i]=temp;
        }
    }
}

int check_r_c(MAT_TYPE r, MAT_TYPE c)
{
    int a, b;
    a = (int)r;
    b = (int)c;
    r -= a;
    c -= b;
    if (fabs(r) < 1e-6 || fabs(c) < 1e-6)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}