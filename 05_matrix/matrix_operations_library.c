#include <stdio.h>
#define MAX_COL 100
#define MAX_ROW 100

void mat_add (int u[][MAX_COL],int v[][MAX_COL],int result[][MAX_COL],int rows,int cols)
{
    int i,j;
    for (i=0;i<rows;i++){
        for (j=0;j<cols;j++){
            result[i][j]=u[i][j]+v[i][j];
        }
    }
}

int main(void)
{
    do{
        int a=0;
        puts("What do you want to operation about matrix. [add...1/dif...2/mul...3/inv...4/adj/...5/ran...6]");
        scanf("%d",&a);
        if(a<1||a>6){
            puts("You haven't enter true number");
        }
    }while(a<1||a>6);

    
    switch (a)
    {
    case 1:

    }
    return 0;
}
