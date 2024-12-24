#include <stdio.h>
#include <cs50.h>

int fact(int x);
int main(void)
{
    int input;
    do{
        input = get_int("Add Your Number : ");
        
    }while (input < 0);
    printf("%i\n",fact(input));
}
int fact(int x)
{
    if(x == 1)
    {
        return 1;
    }
    else
        return x * fact(x - 1); // this is recursion.
}