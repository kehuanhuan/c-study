#include "include/functions.h"

int main(void)
{
    whoaim();
    int a = 8;
    int b = 9;
    printf("a origin value is %d\n", a);
    switchAtoB(&a, &b);
    printf("a now value is %d\n", a);

    struct Book bk1;

    bk1.title = "C Programming, by kehuanhuan";
    bk1.pages = 10;

    printBook(&bk1);

    return 0;
}

