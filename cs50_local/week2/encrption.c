#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command_line argument\n");
        return 1;
    }
    else
    {
        int k = get_int("Enter Kye : ");
        string en = argv[1];
        for (int i = 0; i < strlen(en); i++)
        {
            printf("%c",en[i]+k);
        }
        printf("\n");
        return 0;
    }
}