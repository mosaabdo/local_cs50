#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int MAX = 3;
    int *x = malloc(MAX * sizeof(int));
    x[0] = 20;
    x[1] = 10;
    x[2] = 15;

    for (int i = 0; i < MAX; i++)
        printf("%i, %p\n",x[i], x[i]);
    free(x);
}