#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *score = malloc(1024 * sizeof(int));
    for(int i = 0; i < 1024; i++)
        printf("%i\n",score[i]);
    free(score);
}