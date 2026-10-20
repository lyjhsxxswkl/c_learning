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

int mat_ran(const Matrix *A)
{
    int z = 0;
    int rank=0;
    Matrix copy=create_matrix(A->row,A->col);

    /*copy matrix A*/
    for(int i=0;i<A->row;i++){
        for(int j=0;j<A->col;j++){
            copy.data[i][j]=A->data[i][j];
        }
    }

    /*a big cycle*/
    for (int o=0;o<A->col;o++)
    {
        int n = -1;
        /*check if o col is 0*/
        for (int i = o; i < A->row; i++)
        {
            if (fabs(copy.data[i][o]) >1e-6)
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