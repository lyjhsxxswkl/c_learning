1， error: passing argument 1 of 'mat_add' from incompatible pointer type [-Wincompatible-pointer-types]
   34 |     mat_add(matrixA,matrixB,2,2);
      |             ^~~~~~~
      |             |
      |             float (*)[2]
/*
问题：头文件函数规定列数为MAX_COL=10，传进去的数组却为2
解决方法：动态分配
*/

2，if (copy.data[o][o] == 0)
/*问题：浮点数精度问题
解决方法：fabs(x) < 1e-6，和1e-6比较

3，动态分配内存忘记释放

4，copy.data[A->row][A->col]
问题：访问越界，最大为 row-1 和 col-1

5，在for循环外面初始化变量，在循环里面需要重置的没有重置
