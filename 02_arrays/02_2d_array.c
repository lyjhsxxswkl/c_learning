#include <stdio.h>
int main(){
    int i,j;
    int m,n;
    int a,b;
    int matrix1[4][3]={0};
    int matrix2[3][4]={0};
    int matrix3[4][4]={0};
    printf("Input the first matrix:\n");
    for (i=0;i<4;i++){
        for (j=0;j<3;j++){
            scanf("%d",matrix1[i][j]);
            if (j==2){
                printf("\n");
            }
        }

    }
    printf("Input the second matrix2\n");
    for (i=0;i<3;i++){
        for (j=0;j<4;j++){
            scanf("%d",&matrix2[i][j]);
            if (j==2){
                printf("\n");
            }
        }
    }
    for (m=0;m<4;m++){
        for (n=0;n<4;n++){
            for (i=0;i<4;i++){
                for (j=0;j<3;j++){
                    for (b=0;b<4;b++){
                        for (a=0;a<3;a++){
                            matrix3[m][n]=matrix1[i][j]*matrix2[a][b];
                        }
                    }
                }
            }
        }
    }
    printf("Your result is:\n");
    for (m=0;m<4;m++){
        for (n=0;n<4;n++){
            printf("%d",matrix3[m][n]);
        }
    }
}