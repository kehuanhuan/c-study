#include<stdio.h>

int main(void)
{

  int a[10] = {3,6,6,1,6,5,5,5,1,6};

  int i = 0;
  int j = 0;
  int temp;

  for (int i = 0; i <  10; ++i)
  {
     if (a[i] < a[i+1])
     {
         temp = a[i];
         a[i] = a[i+1];
         a[i+1] = temp;
     } else {
        break;
     }
  }

  for (int k = 0; k < 10; ++k)
  {
      printf("%d\n", a[k]);
  }
}

/********************************
 *函数名：swap
 *作用：交换两个数的值
 *参数：交换的两个数
 *返回值：无
 ********************************/
void mswap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    return ;
}
