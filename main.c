#include <stdio.h>
#include "static_lib.h"
#define SUM (b*b)

int main(void)
{
    int a, b;
    char *ip_str;
    ip_str = get_local_ip();
    printf("please input a and b\n");
    scanf("%d %d", &a, &b);
    printf("the add : %d\n", add(a, SUM));
    printf("the sub : %d\n", sub(a, SUM));
    printf("the mul : %d\n", mul(a, SUM));
    printf("the div : %d\n", div(a, SUM));
    printf("the local ip : %s\n", ip_str);
    return 0;

}
