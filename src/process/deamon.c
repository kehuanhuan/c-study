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

void mydaemon(int ischdir,int isclose, int pronum)
{
    pid_t pid, sid;

    // 创建子进程，然后父进程退出
    pid = fork();
    if(pid < 0){
        perror("fork");
        exit(EXIT_FAILURE);
    } else if(pid > 0) {
        exit(EXIT_SUCCESS);
    }
    // 子进程
    // 创建新会话和新进程组
    if((sid = setsid()) < 0){
        perror("setsid");
        exit(EXIT_FAILURE);
    }
    // 改变当前的工作目录到根目录
    if((chdir("/")) < 0){
        perror("chdir");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < pronum; ++i)
    {
        pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0){
            i = pronum;
        }
    }
    // 改变目录文件的创建模式
    umask(0);
    // 关闭不必要的文件描述符
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

}
