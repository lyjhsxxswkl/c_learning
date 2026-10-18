 error: passing argument 1 of 'mat_add' from incompatible pointer type [-Wincompatible-pointer-types]
   34 |     mat_add(matrixA,matrixB,2,2);
      |             ^~~~~~~
      |             |
      |             float (*)[2]
/*
问题：头文件函数规定列数为MAX_COL=10，传进去的数组却为2
解决方法：动态分配
*/