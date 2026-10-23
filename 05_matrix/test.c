#include<stdio.h>
#include"matrix.h"

int main()
{
    int r=3,c=3;

Matrix A=create_matrix(r,c);
Matrix B=create_matrix(r,c);
/*Matrix C=create_matrix(r,c);*/

printf("Enter number of matrix A:\n");

for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        scanf("%lf",&A.data[i][j]);
    }
}

int test=mat_inv(&A,&B);
if(test=0){
    puts("Your matrix haven't inv");
}else{
/*float result=mat_det(&A);

printf("/nEnter number of matrix B:/n");

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
*/

for(int i=0;i<B.row;i++){
    for(int j=0;j<B.col;j++){
        printf("%.1f ",B.data[i][j]);
    }
}
/*printf("%.2f",result);*/
free_matrix(&A);
free_matrix(&B);
/*free_matrix(&C);*/
}
return 0;
}