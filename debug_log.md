 error: passing argument 1 of 'mat_add' from incompatible pointer type [-Wincompatible-pointer-types]
   34 |     mat_add(matrixA,matrixB,2,2);
      |             ^~~~~~~
      |             |
      |             float (*)[2]
/*
问题：头文件函数规定列数为MAX_COL=10，传进去的数组却为2
解决方法：动态分配
*/
#include <stdio.h>
#include <stdlib.h>

    int x,y;
    int m,n;
    int i,j;
    int k;

void mat_input(int w,float matrixA[][MAX_COL],float matrixB[][MAX_COL])
{
    do {
        puts("Enter all numbers separated by spaces");
        printf("Enter the dimensions of the first matrix:");
        scanf("%d %d",&x,&y);
        if(w>3){
            break;
        }
        printf("Enter the column of the second matrix:");
        scanf("%d",&n);
        if (x>MAX_ROW||y>MAX_COL||n>MAX_COL){
            puts("\nIt can only calculate matrices up to 100*100\n");
        }
        else if (x<=0||y<=0||n<=0){
            puts("\nPlease Enter a number greater than 0,thanks. :)\n");
        }
    }while(x>MAX_ROW||y>MAX_COL||n>MAX_COL||x<=0||y<=0||n<=0);

    printf("Input the first matrix:\n");

    for (i=0;i<x;i++){
        for (j=0;j<y;j++){
            scanf("%d",&matrixA[i][j]);
        }
    }
    if(w>3){
        return;
    }
    
    printf("Input the second matrix\n");
    
    for (i=0;i<y;i++){
        for (j=0;j<n;j++){
            scanf("%d",&matrixB[i][j]);
        }
    }
}

void mat_add (float matrixA[][MAX_COL],float matrixB[][MAX_COL],float matrixC[][MAX_COL],int rows,int cols)
{
    int i,j;
    for (i=0;i<rows;i++){
        for (j=0;j<cols;j++){
            matrixC[i][j]=matrixA[i][j]+matrixB[i][j];
        }
    }
}

void mat_dif (float matrixA[][MAX_COL],float matrixB[][MAX_COL],float matrixC[][MAX_COL],int rows,int cols)
{
    int i,j;
    for (i=0;i<rows;i++){
        for (j=0;j<cols;j++){
            matrixC[i][j]=matrixA[i][j]-matrixB[i][j];
        }
    }
}

void mat_mul(float matrixA[][MAX_COL],float matrixB[][MAX_COL],float matrixC[][MAX_COL],int rows,int cols)
{
    int i,j;
    for (i=0;i<x;i++){
        for (j=0;j<n;j++){
            matrixC[i][j]=0;
            for (k=0;k<y;k++){
                matrixC[i][j]+=matrixA[i][k]*matrixB[k][j];
            }
        }
    }
}