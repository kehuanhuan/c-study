#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <net/if.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "../../include/functions.h"

#define ERRORIP "cannot find host ip"

char *get_local_ip(void)
{
    int sfd, intr;
    struct ifreq buf[16];
    struct ifconf ifc;

    sfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sfd < 0)
    {
        return ERRORIP;
    }

    ifc.ifc_len = sizeof(buf);
    ifc.ifc_buf = (caddr_t)buf;

    if (ioctl(sfd, SIOCGIFCONF, (char *)&ifc))
    {
        return ERRORIP;
    }

    intr = ifc.ifc_len / sizeof(struct ifreq);

    while (intr-- > 0 && ioctl(sfd, SIOCGIFADDR, (char *)&buf[intr]))
    {
        close(sfd);
    }

    return inet_ntoa(((struct sockaddr_in*)(&buf[intr].ifr_addr))-> sin_addr);
}

void switchAtoB(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

char whoaim()
{
    printf("I am a dynamc lib\n");
}

int testMalloc()
{
    char *str;

    while (1) {
        sleep(2);
        str = (char *) malloc(100000);
        printf("malloc size is %d\n", sizeof(str));
    }
    return sizeof(str);
}

void printBook(struct Book *book)
{
    printf("Book title is %s\n", book->title);
    printf("Book pages is %d\n", book->pages);
}


void printPageSize()
{
    printf("page-size: %ld\n",sysconf(_SC_PAGESIZE));
}



