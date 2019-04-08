#include "include/functions.h"

int main(void)
{
    whoaim();
    int a = 8;
    int b = 9;
    printf("a origin value is %d\n", a);
    change(&a, &b);
    printf("a now value is %d\n", a);

    return 0;
}
