#include <stdio.h>
int main(){
    int i,j,k;
    int matrix1[4][3]={0};
    int matrix2[3][4]={0};
    int matrix3[4][4]={0};
    printf("Input the first matrix:\n");
    for (i=0;i<4;i++){
        for (j=0;j<3;j++){
            scanf("%d",&matrix1[i][j]);
            if (j==2){
                printf("\n");
            }
        }

    }
    printf("Input the second matrix2\n");
    for (i=0;i<3;i++){
        for (j=0;j<4;j++){
            scanf("%d",&matrix2[i][j]);
            if (j==3){
                printf("\n");
            }
        }
    }
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            matrix3[i][j]=0;
            for (k=0;k<3;k++){
                matrix3[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }
    printf("Your result is:\n");
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            printf("%d ",matrix3[i][j]);
            if (j==3){
                printf("\n");
            }
        }
    }
}