void mat_mul(matrixA[][MAX_COL],matrixB[][MAX_COL],i,j)
{
    for (i=0;i<x;i++){
        for (j=0;j<n;j++){
            matrixC[i][j]=0;
            for (k=0;k<y;k++){
                matrixC[i][j]+=matrixA[i][k]*matrixB[k][j];
            }
        }
    }
}