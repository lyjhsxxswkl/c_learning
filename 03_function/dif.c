#include <stdio.h>
#define MAX_COL 100
#define MAX_ROW 100
void mat_add (int u[][MAX_COL],int v[][MAX_COL],int result[][MAX_COL],int rows,int cols)
{
    int i,j;
    for (i=0;i<rows;i++){
        for (j=0;j<cols;j++){
            result[i][j]=u[i][j]-v[i][j];
        }
    }
}