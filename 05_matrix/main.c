#include <stdio.h>
#include <math.h>
#include "matrix.h"

int main(void)
{
     row;
    int col;

    do
    {
        int a = 0;
        puts("What do you want to operation about matrix. [add...1/dif...2/mul...3/inv...4/adj...5/ran...6/del...7]");
        scanf("%d", &a);
        if (a < 1 || a > 7)
        {
            puts("You haven't enter true number");
        }
    } while (a < 1 || a > 7);

    switch(a){
        /*Make sure matrix's row and col*/
        puts("Enter your matrix's row and col");
        scanf("")
        case 1:Matrix A=create_matrix()
    }
    return 0;
}
