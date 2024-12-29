#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = "Hi!\nbay!";

    for(;*s != '\0';)
        printf("%c",*s++);
    printf("\n");
}