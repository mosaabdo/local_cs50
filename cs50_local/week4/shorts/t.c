#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *x = malloc(sizeof(char));  
    if(x == NULL)
        return 1; 
    scanf("%s", x);

    int i = 0, length = strlen(x);
    printf("length is: %d\n", length);

    while (x[i] != '\0')
    {
        printf("%c", x[i]);
        i++;
    }
    printf("\n");
    
    free(x);
    return 0;
}