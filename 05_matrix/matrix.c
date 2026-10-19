#include <stdio.h>
#include<stdlib.h>
#include"matrix.h"


Matrix create_matrix(int r,int c){
    Matrix m;
    m.row=r;
    m.col=c;

    m.data=(float**)malloc(r*sizeof(float*));

    for(int i=0;i<c;i++){
        m.data[i]=(float*)malloc(sizeof(float));
    }
    return m;
}

void free_matrix(Matrix *m){
    for (int i=0;i<m->row;i++){
        free(m->data[i]);
    }

    free(m->data);
    m->data=0;
}

void mat_add (const Matrix *A,const Matrix *B,Matrix *C)
{
    for (int i=0;i<C->row;i++){
        for (int j=0;j<C->col;j++){
            C->data[i][j]=A->data[i][j]+B->data[i][j];
        }
    }
}

void mat_dif (const Matrix *A,const Matrix *B,Matrix *C)
{
    for (int i=0;i<C->row;i++){
        for (int j=0;j<C->col;j++){
            C->data[i][j]=A->data[i][j]-B->data[i][j];
        }
    }
}

int mat_ran (const Matrix *A)
{
    int m=0,n=0;
    int o=0,z=0;
    float matrixB[A->col-o];
    float matrixC[A->row-1][A->col-1];
    for(int i=o;i<A->row;i++){
        for(int j=o;j<A->col;j++){
            if(A->data[i][j]==0){
                m++;
            }
        }
    }

    if(m==A->col-o){
        return o;
    }

    for(int i=0;i<A->row;i++){
        for(int j=0;j<A->col;j++){
            if(A->data[i][j]!=0){
                n=i;
            }
        }
    }

    for(int j=0;j<A->row;j++){
        matrixB[j]=A->data[o][j];
    }

    for(int j=0;j<A->row;j++){
        A->data[o][j]=A->data[n][j];
        A->data[n][j]=matrixB[j];
    }

    z=A->data[o][o];

    for(int j=0;j<A->row;j++){
        A->data[o][j]/=z;
    }

    for(int i=o+1;i<A->row;i++){
        z=A->data[i][o];
        for(int j=o;j<A->col;j++){
            A->data[i][j]-=z*A->data[o][j];
        }
    }

    for(int i=o+1;i<A->row;i++){
        for(int j=o+1;j<A->col;j++){
            matrixC[i-1][j-1]=A->data[i][j];
        }
    }

    o++;

    mat_adj();
}
