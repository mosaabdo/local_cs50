#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int prossece;
    printf("select your prossece:\n");
    printf("1] add\t2] read\n");
    scanf("%d", &prossece);
    getchar();

    if(prossece < 1 || prossece > 2)
        printf("error!\n");

    if(prossece == 1)
    {
        FILE *file = fopen("phonebook.csv", "a");
        if(file == NULL)
        {
            printf("error file is'nt found\n");
            return 2;
        }
        
        char *name = get_string("name: ");
        char *number = get_string("number: ");
        
        fprintf(file, "%s, %s\n", name, number);
        fclose(file);
    }
    else
    {
        FILE *file = fopen("phonebook.csv", "r");
        if(file == NULL)
        {
            printf("error file is'nt found\n");
            return 2;
        }
        
        int ch; // يجب أن يكون int لأن fgetc قد يرجع EOF
        while ((charcter = fgetc(file)) != EOF)
        {
            putchar(charcter);
        }
        fclose(file);

    }
    
    return 0;
}