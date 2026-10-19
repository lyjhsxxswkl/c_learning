#include<stdio.h>
#include"matrix.h"

int main()
{
    int r=2,c=3;

Matrix A=create_matrix(r,c);
Matrix B=create_matrix(r,c);
Matrix C=create_matrix(r,c);

printf("Enter number of matrixA");

for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        scanf("%f",&A.data[i][j]);
    }
}

printf("Enter number of matrixB");

for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        scanf("%f",&B.data[i][j]);
    }
}

mat_add(&A,&B,&C);

puts("\nThe result is:");

for(int i=0;i<C.row;i++){
    for(int j=0;j<C.col;j++){
        printf("%.2f",C.data[i][j]);
    }
}

free_matrix(&A);
free_matrix(&B);
free_matrix(&C);

return 0;
}