#include <stdio.h>
#include <cs50.h>

long luhan (int l, long c, int e);
int main (void)
{
    long card_num = get_long("Enter Card Number : ");
    int brelast_num, end_num;
    luhan(brelast_num,card_num,end_num);
}
int check_type (int type)
{
    if(type )
    {
         printf("Type is AMEX\n");
    }
    else if (type)
    {
         printf("Type is VISA\n");
    }
    else if (type)
    {
         printf("Type is MASTERCARDE\n");
    }
    else
    {
         printf("INVALID\n");
    }
    
}
long luhan (int l,long c, int e)
{
    for(int i = 0; i < c; i++) // this loop for take cached num
    {
        e = c %10;  // e is end_num : this line take last number from card number evry loop 
        c = c /10;  // c is card_number : thes line update c valuo after lost last number evry loop
        l = c %10;  // l = belast_num : this line take a befor num of last num
        c = c /10;  // thes line update c valuo after lost last number evry loop
        printf("== %i\n",e);
        printf("%i\n",l*2);
    }
}