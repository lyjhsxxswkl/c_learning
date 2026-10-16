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
