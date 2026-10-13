#include <stdio.h>
#define MAX_ROW 100
#define MAX_COL 100
int main(){
    int i,j,k;
    int x,y;
    int n;
    int matrixA[MAX_ROW][MAX_COL];
    int matrixB[MAX_ROW][MAX_COL];
    int matrixC[MAX_ROW][MAX_COL];

        do {
            puts("Enter all numbers separated by spaces");
            printf("Enter the dimensions of the first matrix:");
            scanf("%d %d",&x,&y);
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

    printf("Input the second matrix\n");
    
    for (i=0;i<y;i++){
        for (j=0;j<n;j++){
            scanf("%d",&matrixB[i][j]);
        }
    }

    for (i=0;i<x;i++){
        for (j=0;j<n;j++){
            matrixC[i][j]=0;
            for (k=0;k<y;k++){
                matrixC[i][j]+=matrixA[i][k]*matrixB[k][j];
            }
        }
    }

    printf("result is:\n");
    for (i=0;i<x;i++){
        for (j=0;j<n;j++){
            printf("%d ",matrixC[i][j]);
        }
    printf("\n");
    }
}