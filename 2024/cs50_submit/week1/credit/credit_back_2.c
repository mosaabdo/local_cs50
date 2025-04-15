#include <stdio.h>
#include <cs50.h>

long luhan (int l, long c, int e);
long check_type (long type);
int main (void)
{
    long card_num = get_long("Enter Card Number : ");
    int brelast_num, end_num;
    luhan(brelast_num,card_num,end_num);
}
long luhan (int l,long c, int e)
{
    int l_sum,e_sum; l_sum = e_sum = 0;
    long const_c_n = c;
    for(int i = 0; i < c; i++) // this loop for take cached num
    {
        e = c %10;  // e is end_num : this line take last number from card number evry loop 
        c = c /10;  // c is card_number : thes line update c valuo after lost last number evry loop
        l = c %10;  // l = belast_num : this line take a befor num of last num
        c = c /10;  // thes line update c valuo after lost last number evry loop
        l = l *2;   // this line for complet luhan algorirhm
        if (l >= 10)// this loop for l > 10 as 12 change to 1 and 2 and add 1+2 to l value >> l = 1+2;
        {
           int x = l %10;
           l = l /10;
           l = l+x;
        }
        l_sum = l_sum + l;
        e_sum = e_sum + e;
        // printf("== %i\n",e);
        // printf("%i\n",l);
    }
    int checker = l_sum+e_sum;
    printf ("l_sum = %i\n",l_sum);
    printf ("e_sum = %i\n",e_sum);
    printf ("checker = %i\n",checker);
    if (checker %10 == 0)
        { check_type(const_c_n);} 
    else
        { printf("INVALID\n"); }
}
long check_type (long type)
{
    for(int i=0; i<type-100; i++)
    {
        type = type /10;
    }
    printf ("%li\n",type);
    if(type == 34 || type == 37)
    {
         printf("Type is AMEX\n");
    }
    else if (type == 51 || type == 52 || type == 53 || type == 54 || type == 55)
    {
         printf("Type is MASTERCARDE\n");
    }
    else if(type == 40)
    {
         printf("Type is VISA\n");
    }
    else
    {
        printf("Type is Not Fund\n");
    }

    
}
