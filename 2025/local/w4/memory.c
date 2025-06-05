#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int s = 3;
    int *x = malloc(s * sizeof(int));
    
    for(int i = 0; i < s; i++)
        x[i] = i + 1;
    for(int i = 0; i < s; i++)
        printf("%d\t", x[i]);

    printf("\n");
    free(x);
    return 0;
}