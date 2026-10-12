#include <stdio.h>
int main(){
    int i,j,k;
    int matrixA[4][3]={0};
    int matrixB[3][4]={0};
    int matrixC[4][4]={0};
    printf("Input the first matrix:\n");
    for (i=0;i<4;i++){
        for (j=0;j<3;j++){
            scanf("%d",&matrixA[i][j]);
        }
    }

    printf("Input the second matrix2\n");
    for (i=0;i<3;i++){
        for (j=0;j<4;j++){
            scanf("%d",&matrixB[i][j]);
        }
    }

    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            matrixC[i][j]=0;
            for (k=0;k<3;k++){
                matrixC[i][j]+=matrixA[i][k]*matrixB[k][j];
            }
        }
    }

    printf("result is:\n");
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            printf("%d ",matrixC[i][j]);
            if (j==3){
                printf("\n");
            }
        }
    }
}