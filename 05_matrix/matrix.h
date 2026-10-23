#ifndef MATRIX_H
#define MATRIX_H

typedef double MAT_TYPE;

    typedef struct
{
    int row;
    int col;
    MAT_TYPE **data;
} Matrix;

Matrix create_matrix(int r, int c);

void free_matrix(Matrix *m);
void mat_add(const Matrix *A, const Matrix *B, Matrix *C);
void mat_dif(const Matrix *A, const Matrix *B, Matrix *C);
int mat_ran(const Matrix *A);
int mat_inv(const Matrix *A, Matrix *B);
MAT_TYPE mat_det(const Matrix *A);

#endif
