#include <stdio.h>

void change(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int argc, char const *argv[])
{
    int a = 2;
    int b=3;

    change(&a, &b);
    printf("a=%d\n b=%d\n", a, b);
    return 0;
}