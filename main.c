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
    time_t timebuf;
    int  fd, len;
    char *buf;

    freopen("deamon.log", "a", stderr);
    mydaemon(0, 1, 2);
    // malloc buf
    len = strlen(ctime(&timebuf));
    buf = malloc(len+1);
    // 子进程主要工作，每10秒钟向日志文件写入当前的时间
    while(1)
    {
        if((fd = open("/var/log/mydaemon.log", O_CREAT | O_WRONLY | O_APPEND,0600)) < 0){
            perror("open file");
            exit(EXIT_FAILURE);
        }
        time(&timebuf);
        bzero(buf, len+1);
        strncpy(buf,ctime(&timebuf),len+1);
        write(fd, buf, len+1);
        close(fd);
        sleep(10);
    }
    free(buf);
    exit(EXIT_SUCCESS);

    return 0;

}
