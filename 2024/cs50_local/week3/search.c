#include<stdio.h>
#include<string.h>
#include<cs50.h>
#include <ctype.h>


/*int main(void) 
{
    int number[] = {20, 500, 10, 5, 100, 1, 50};
    int input = get_int("Enter Your Number : ");

    for(int i = 0, x = 0, length = sizeof(number)/sizeof(number[0]); i < length; i++)
    {
        if (number[i] == input)
        {
            printf("Found in feld [%i]\n",i);
            return 0;
        }
    }
    printf("Not Foun\n");
    return 1;
}*/

int main(void)
{
    string names[] = {"mousa", "ahmed", "mohamed", "ibraheam", "husean"};
    string input = get_string("Add Name : ");
    int length = sizeof(names)/sizeof(names[0]);

    for (int i = 0, x = 0; i < length; i++)
    {
        if(strcmp(names[i], input) == 0)
        {
            printf("Found in feld [%i]\n",i);
            return 0;
        }
    }
    printf("Not Foun\n");
    return 1;
}