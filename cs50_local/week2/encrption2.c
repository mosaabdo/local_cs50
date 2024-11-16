
#include <stdio.h>
#include <cs50.h>
#include <string.h>

void encreption (int k, string input);
void decncreption (string input);
int main (int argc, string argv[])
{
    int ky = get_int("Enter Kye : ");
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            encreption(ky, argv[i]);
        }
        printf("\n");
        for (int x = 1; x < argc; x++)
        {
            printf("%s ",argv[x]);
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf ("Missing command line argument\n");
        return 1;
    }
}
void encreption (int k, string input)
{
    string en = input;
        for (int i = 0; i < strlen(en); i++)
        {
            printf("%c",en[i]+k);
        }
        printf(" ");
}