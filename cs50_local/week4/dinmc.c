#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *input = malloc(sizeof(char)+1);

    printf("input : ");
    scanf("%s", input);
    printf("output: %s\n", input);
    
    free(input);
}
// ! check valrang error