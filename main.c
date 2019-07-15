#include <stdio.h>

#include<stdlib.h>
#include<sys/types.h>
#include <errno.h>
#include<sys/stat.h>

#include<fcntl.h>

#include "src/algorithms/algorithms.h"
#include "src/tools/functions.h"
#include "src/process/deamon.h"

#define BUF_SIZE 10
extern int errno ;

int main(void)
{
    freopen("deamon.log", "a", stderr);
    mydaemon(0, 1, 2);

    FILE * pf;
    int errnum;
    pf = fopen ("unexist.txt", "rb");
    if (pf == NULL)
    {
      errnum = errno;
      perror("通过 perror 输出错误");
     }
     else
     {
        fclose (pf);
     }

     while (1) {
        sleep(10);
     }

    return 0;

}
