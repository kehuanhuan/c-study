#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<errno.h>
#include<syslog.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

#include "src/algorithms/algorithms.h"
#include "src/tools/functions.h"
#include "src/process/deamon.h"

#define BUF_SIZE 10
extern int errno ;

int main(void)
{

  int[] a = [3,6,6,6,6,5,5,5,1,6];

  int i = 0;
  int j = 0;

  for (int i = 0; i < 10; ++i)
  {
     for (int j = 1; j < 9; ++j)
     {
         if (a[i] < a[j])
         {
             swap(a[i], a[j]);
         }
     }
  }

printf("%d\n", a[7]);

}

