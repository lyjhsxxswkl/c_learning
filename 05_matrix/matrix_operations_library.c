#include <stdio.h>
#define MAX_COL 100
#define MAX_ROW 100

void mat_input(int w)
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

void mat_add (int matrixA[][MAX_COL],int matrixB[][MAX_COL],int matrixC[][MAX_COL],int rows,int cols)
{
    int i,j;
    for (i=0;i<rows;i++){
        for (j=0;j<cols;j++){
            matrixC[i][j]=matrixA[i][j]+matrixB[i][j];
        }
    }
}

void mat_dif (int matrixA[][MAX_COL],int matrixB[][MAX_COL],int matrixC[][MAX_COL],int rows,int cols)
{
    int i,j;
    for (i=0;i<rows;i++){
        for (j=0;j<cols;j++){
            matrixC[i][j]=matrixA[i][j]-matrixB[i][j];
        }
    }
}

void mat_mul(int matrixA[][MAX_COL],int matrixB[][MAX_COL],int matrixC[][MAX_COL],rows,int cols)
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

int main(void)
{
    do{
        do{
        int a=0;
        puts("What do you want to operation about matrix. [add...1/dif...2/mul...3/inv...4/adj...5/ran...6]");
        scanf("%d",&a);
        if(a<1||a>6){
            puts("You haven't enter true number");
        }
    }while(a<1||a>6);

    mat_input(a);
    
    switch (a)
    {
    case 1:

    }
    }while ()
    return 0;
}
