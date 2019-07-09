#include <stdio.h>
#include "src/algorithms/algorithms.h"
#include "src/tools/functions.h"

#define BUF_SIZE 10

int main(void)
{
    int n;
    int array[BUF_SIZE] = {12,85,25,16,34,23,49,95,17,61};
    int maxlen = BUF_SIZE;

    printf("排序前的数组\n");
    display(array, maxlen);

    quicksort(array, maxlen, 0, maxlen-1);  // 快速排序

    printf("排序后的数组\n");
    display(array, maxlen);

    return 0;

}
