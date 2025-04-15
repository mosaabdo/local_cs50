#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main (int argc, string argv[])
{
    printf("Hello, ");
    for (int i = 1; i < argc; i++)
    {
        printf("%s ",argv[i]);
    }
    printf("\n");
}


