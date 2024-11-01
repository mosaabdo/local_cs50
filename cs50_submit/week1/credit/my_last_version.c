#include <stdio.h>
#include <cs50.h>

int luhan(long c);
void check_type(long type);
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
void check_type (long type)
{
    long c = type;
    // check even or odd valu in the card nuber filde
    /*
    int count_of_filed = 1;
    for(int i=0; i<c; i++)
    {
        c = c/10;
        count_of_filed++;
    }
    */
    int count_of_filed = 2;
    while (type >= 100)
    {
        type /= 10;
        count_of_filed++; //this line = /* for(int i=0...)^ */
    }
    if(type == 34 || type == 37)
    {
        if (count_of_filed == 15)
         printf("Type is AMEX\n");
        else
         printf("INVALID\n");
    }
    else if (type >= 51 && type <= 55)
    {
         if (count_of_filed == 16)
            printf("Type is MASTERCARD\n");
        else
         printf("INVALID\n");

    }
    else if(type >= 40 && type <= 49)
    {
        if (count_of_filed == 13 || count_of_filed == 16)
         printf("Type is VISA\n");
        else
         printf("INVALID\n");
    }
    else
        { printf("INVALID\n"); }
}
int luhan(long c)
{
    long c_valu = c;
    //take end and be for end number in the varible and applay luhan algrthime
    int end_sum,b_end_sum; end_sum = b_end_sum = 0;

    // for(int i=0; i<c_valu+10; i++) // this line = for(;c_valu;)
    for(;c_valu;) //look up line ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
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
