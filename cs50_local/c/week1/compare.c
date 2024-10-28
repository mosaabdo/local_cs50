#include<stdio.h>
#include <cs50.h>
// <cs50> is custon lib for cs50 include some function as get_ine...

int main (void)
{
    int x,y;
    x = get_int("Enter X Value :");
    y = get_int("Enter Y Value :");

    if (x > y)
        {printf("[%i] not less than [%i]\n",x,y);}
    else if (x<y)
        {printf("[%i] less than [%i]\n",x,y);}
    else 
        {printf ("[%i] equal [%i]\n",x,y);}
}