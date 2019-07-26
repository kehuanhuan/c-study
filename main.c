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
    // freopen("deamon.log", "a", stderr);
    // mydaemon(0, 0, 0);

    char *a;
    int n =1000;

    int b;

    a = "中国ffff";

    b = a;

    printf("%p\n", b);
    printf("%s\n", a);

    while(1)
    {
        sleep(1);

        a = malloc(1024*n*sizeof(char));

        for (int j = 0; j < n; ++j)
        {
            a[j*1024] = 'a';
        }

    }

    exit(EXIT_SUCCESS);

    return 0;

}
