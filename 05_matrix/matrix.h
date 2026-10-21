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
void mat_dif(const Matrix *A,const Matrix *B,Matrix *C);
int mat_ran(const Matrix *A);
void mat_inv(Matrix *A,Matrix *B);
float mat_det(const Matrix *A);

#endif
