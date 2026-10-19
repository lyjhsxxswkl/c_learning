#include<stdio.h>
#include"matrix.h"

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
