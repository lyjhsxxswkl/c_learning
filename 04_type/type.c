#include <stdio.h>
#include <limits.h>

int main()
{
    printf("char               :%d~%d\n",CHAR_MIN,CHAR_MAX);
    printf("signed char        :%d~%d\n",SCHAR_MIN,SCHAR_MAX);
    printf("unsigined char     :%d~%d\n",0,UCHAR_MAX);

    printf("short              :%d~%d\n",SHRT_MIN,SHRT_MAX);
    printf("int                :%d~%d\n",INT_MIN,INT_MAX);
    printf("long               :%ld~%ld\n",LONG_MIN,LONG_MAX);

    printf("unsigined short    :%u~%u\n",0,USHRT_MAX);
    printf("unsigined          :%u~%u\n",0,UINT_MAX);
    printf("unsigined long     :%lu~%lu\n",0,ULONG_MAX);

    return 0;
}



