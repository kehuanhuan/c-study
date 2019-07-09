#include <stdio.h>
#include <stdlib.h>   // exit()
#include <unistd.h>   // fork() setsid() chdir() close()
#include <sys/types.h>    // fork() umask()
#include <sys/stat.h> // umask()

void mydaemon(int ischdir,int isclose)
{
    // 调用setsid() 的不能是进程组组长，当前程序有可能是进程组组长
    pid_t pid = fork();
    // 非子进程则退出
    if(pid != 0)
        exit(-1);
    // 父进程退出，留下子进程

    // 创建一个新的会话期，从而脱离原有的会话期
    // 进程同时与控制终端脱离
    setsid();
    // 此时子进程成为新会话期的领导和新的进程组长
    // 但这样的身份可能会通过fcntl去获到终端
    pid = fork();
    // 非子进程则退出
    if(pid != 0)
        exit(-1);
    // 此时留下来的是孙子进程,再也不能获取终端
    // 通常来讲, 守护进程应该工作在一个系统永远不会删除的目录下
    if(ischdir == 0)
    {
        chdir("/");
    }
    // 关闭输入输出和错误流 (通过日志来查看状态)
    if(isclose == 0)
    {
        close(0);
        close(1);
        close(2);
    }

    //去掩码位
    umask((mode_t)0);//sys/stat.h
}

