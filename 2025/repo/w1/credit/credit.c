#include <stdio.h>
#include <string.h>
#include <cs50.h>

bool luhan (string num);
int main(void)
{
    string c_number = get_string("add card number : ");
    bool res = luhan(c_number);
    if(res == false)
    {   
        printf("INVALID\n");
        return 1;
    }
    else
    {
        printf("True\n");
    }
}

bool luhan (string num)
{
    int c_size = strlen(num);
    if (c_size != 13 && c_size != 15 && c_size != 16)
        return false;
    else
    {
        int c_n[c_size];
        for(int i = 0; i < c_size; i++)
        {
            c_n[i] = num[i] - '0';
        }
    }
        
      

}