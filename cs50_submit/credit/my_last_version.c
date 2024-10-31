#include <stdio.h>
#include <cs50.h>

int luhan(long c);
int check_type(long type);
int main(void)
{
    long card_number=get_long("Enter Card Number : ");
    luhan(card_number);
    if(luhan(card_number) % 10 == 0)
    {
        check_type(card_number);
    }
    else 
    {
        printf("INVALID\n");
    }
}
int check_type (long type)
{
    while (type >= 100) 
    {
        type /= 10;
    }
    if(type == 34 || type == 37)
    { printf("Type is AMEX\n"); }
    else if (type >= 51 && type <= 55 || type >=20 && type <=22)
        { printf("Type is MASTERCARDE\n"); }
    else if(type >= 40 && type <= 49)
        { printf("Type is VISA\n"); }
    else
        { printf("Type is Not Fund\n"); }   
}
int luhan(long c)
{
    long c_valu = c;
    // check even or odd valu in the card nuber filde
    // int count_of_filed = 1;
    // for(int i=0; i<c; i++)
    // {
    //     c = c/10;
    //     count_of_filed++;
    // }
    // count_of_filed = count_of_filed %2;
    // printf("filde = %i\n",count_of_filed);
    //take end and be for end number in the varible and applay luhan algrthime
    int end_sum,b_end_sum; end_sum = b_end_sum = 0; 

    for(int i=0; i<c_valu+10; i++)
    {
        int end = c_valu %10;
        c_valu = c_valu /10;
        int b_end = c_valu %10;
        c_valu = c_valu /10;
        b_end = b_end *2;
        if(b_end >=10)
        {
            int x = b_end %10;
            b_end = b_end /10;
            b_end = b_end + x;
        }
        end_sum = end_sum + end;
        b_end_sum = b_end_sum + b_end;
    }
        int tottle= end_sum+b_end_sum;
        return tottle;
}
