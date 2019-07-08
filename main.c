#include "include/functions.h"

int main(void)
{
    whoaim();
    int a = 8;
    int b = 9;
    printf("a origin value is %d\n", a);
    change(&a, &b);
    printf("a now value is %d\n", a);

    struct Book bk1;

    bk1.title = "C Programming, by kehuanhuan";
    bk1.pages = 10;

    printBook(&bk1);

    testMalloc();

    return 0;
}

void printBook(struct Book *book)
{
    printf("Book title is %s\n", book->title);
    printf("Book pages is %d\n", book->pages);
}
