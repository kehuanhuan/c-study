#include <stdio.h>
#include "static_lib.h"

int main(void)
{
    char *ip_str;
    ip_str = get_local_ip();
    printf("the local ip : %s\n", ip_str);
    return 0;

}
