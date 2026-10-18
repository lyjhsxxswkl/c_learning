#include <stdio.h>

int mat_adj (float matrixA[][MAX_COL],int row,int col)
{
    int i,j,m,n,z,o=0;
    float matrixB=[col];
    float matrixC=[row-1][col-1];
    for(i=0;i<row;i++){
        if(matrixA[i][0]==0){
            m++;
        }
        else{
            n=i;
        }
    }
    if(m==col-o){
        return o;
    }

    if(matrix[0][0]==0){
        for(j=0;j<col;j++){
            matrixB[j]=matrixA[0][j];
        }
        for(j=0;j<col;j++){
            matrixA[0][j]=matrixA[n][j];
            matrixA[n][j]=matrixB[];
        }
    }

    z=matrixA[0][0];

    for(j=0;j<row;j++){
        matrixA[0][j]/=z;
    }

    for(i=1;i<row;i++){
        z=matrixA[i][0];
        for(j=0;j<col;j++){
            matrixA[i][j]-=z*matrixA[0][j];
        }
    }

    for(i=1;i<row;i++){
        for(j=1;j<col;j++){
            matrixC[i-1][j-1]=matrixA[i][j];
        }
    }

    o++;

    mat_adj(matrixC[][col],row-1,col-1);
}
