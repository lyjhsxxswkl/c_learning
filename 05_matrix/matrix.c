#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

Matrix create_matrix(int r, int c)
{
    Matrix m;
    m.row = r;
    m.col = c;

    m.data = (float **)malloc(r * sizeof(float *));

    for (int i = 0; i < c; i++)
    {
        m.data[i] = (float *)malloc(sizeof(float));
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

void mat_mul(const Matrix *A, const Matrix *B, Matrix *C){

    for (int i=0;i<A->row;i++){
        for (int j=0;j<B->col;j++){
            C->data[i][j]=0;
            for (int k=0;k<A->col;k++){
                C->data[i][j]+=A->data[i][k]*B->data[k][j];
            }
        }
    }
}

int mat_ran(const Matrix *A)
{
    int z = 0;
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

        /*chang the main element to the first row*/
        for (int j = 0; j < A->col; j++)
        {
            float temp;
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

void mat_inv(Matrix *A, Matrix *B)
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

    /*check if matrix is */
}

float mat_det(const Matrix *A)
{
    int b = 0;
    float m = 1;
    float temp;
    float det = 1;
    float z = 0;

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