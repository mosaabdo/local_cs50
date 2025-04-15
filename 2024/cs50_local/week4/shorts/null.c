#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *a = malloc(sizeof(int));
  
    if(a == NULL)
        return 1;
  
    *a = 9;

    printf("%p, %d", a, *a);
    free(a);

}