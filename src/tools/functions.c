#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <net/if.h>
#include <arpa/inet.h>

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