#include <stdio.h>
#include <cs50.h>

int luhan(long c);
void check_type(long type);

int main(void)
{
    long card_num = get_long("Enter Card Number : ");
    int valid = luhan(card_num);

    if (valid)
    {
        check_type(card_num);
    }
    else
    {
        printf("INVALID\n");
    }
}

int luhan(long c)
{
    int l_sum = 0, e_sum = 0;
    bool is_even_position = false;

    while (c > 0)
    {
        int digit = c % 10;

        if (is_even_position)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = digit % 10 + 1;
            }
            l_sum += digit;
        }
        else
        {
            e_sum += digit;
        }

        is_even_position = !is_even_position; 
        c /= 10;  
    }

    int checker = l_sum + e_sum;
    return checker % 10 == 0; 
}

void check_type(long type)
{
    while (type >= 100) 
    {
        type /= 10;
    }
    if (type == 34 || type == 37)
    {
        printf("Type is AMEX\n");
    }
    else if (type >= 51 && type <= 55)
    {
        printf("Type is MASTERCARD\n");
    }
    else if (type / 10 == 4) 
    {
        printf("Type is VISA\n");
    }
    else
    {
        printf("Type is Not Found\n");
    }
}
