#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool check_length(string input, int length);
int chang_to_num(string input, int i);
int luhn(int input[], int length);
int type(int input[], int length);
int main(void)
{
    string user_input = get_string("Number: ");
    int length = strlen(user_input);

    if(check_length(user_input, length) >= 1)
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {
        int card_of_num[length];
        for(int i = 0; i < length; i++)
            card_of_num[i] = chang_to_num(user_input, i);

        int result = luhn(card_of_num, length);

        if(result == 0)
        {
            type(card_of_num, length);
        }

        else
            printf("INVALID\n");

    }
}
bool check_length(string input,int length)
{
    if(length != 13 && length != 15 && length != 16)
        return 1;

    else
       return 0;
}
int chang_to_num(string input, int i)
{
    int card_of_num = input[i] - '0';
    return card_of_num;
}
int luhn(int input[], int length)
{
    int end_index = length -1, befor_end = end_index -1, sum_even = 0, sum_odd = 0, temprorry = 0, totle = 0;
    for(int i = 0; i < length; i++)
    {
        if(befor_end < 0)
            i++;
        else
        {
            temprorry = input[befor_end] * 2;
            if(temprorry > 9)
            {
                temprorry = (temprorry / 10) + (temprorry % 10);
            }
            sum_odd = sum_odd + temprorry;
            sum_even = sum_even + input[end_index];
            end_index = end_index - 2; befor_end = befor_end - 2;
        }
    }
    if(length % 2 != 0 )
        sum_even = sum_even + input[0];

    totle =  sum_even + sum_odd;

    if(totle % 10 == 0)
        return 0;
    else
        return 1;
}
int type(int input[], int length)
{

if((length == 13 || length == 16) && input[0] == 4)
{
    printf("VISA\n");
    return 0;
}
else if(length == 16 && input[0] == 5 && (input[1] >= 1 && input[1] <= 5))
{
    printf("MASTERCARD\n");
    return 0;
}

else if(length == 15 && input[0] == 3 && (input[1] == 4 || input[1] == 7))
{
    printf("AMEX\n");
    return 0;
}
else
{
    printf("INVALID\n");
    return 1;
}

}
