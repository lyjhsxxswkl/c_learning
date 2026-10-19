#ifndef MATRIX_H
#define MATRIX_H

typedef struct{
    int row;
    int col;
    float **data;
}Matrix;

Matrix create_matrix(int r, int c);
void free_matrix(Matrix *m);
void mat_add(const Matrix *A,const Matrix *B,Matrix *C);

#endif
