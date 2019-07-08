#include <stdio.h>
#define N 1000

int firstA()
{
    int i, p, q, t, id[N];
    for (int i = 0; i < N; i++)
    {
        id[i]++;
    }
    while (scanf("d% d% \n", &p, &q) == 2) {
        if (id[q] == id[p])
        {
            continue;
        }

        for (int t = id[p], i = 0; i < N; i++)
        {
            if (id[i] == t)
            {
                id[i] = id[q];
            }

            printf(" %d %d\n", p, q);
        }

    }
}