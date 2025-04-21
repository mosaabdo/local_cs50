#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    int anum[3];
    string num = "123";
    for(int i = 0; i < 3; i++)
    {
        anum[i] = num[i] - '0';
        printf("%c  %d\n",num[i] + num[i+1], anum[i] + num[i+1]);
    }


}