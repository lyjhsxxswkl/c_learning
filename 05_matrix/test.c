#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

int main(void)
{
    float matrixA[2][2];
    float matrixB[2][2];
    float matrixC[2][2];
    int i,j;

    srand(time(0));

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            matrixA[i][j]=(float)(rand()%10);
            matrixB[i][j]=(float)(rand()%10);
        }
    }
    
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d",matrixA[i][j]);
        }
    }

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d",matrixB[i][j]);
        }
    }    

    mat_add(matrixA,matrixB,2,2);

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d",matrixC[i][j]);
        }
}