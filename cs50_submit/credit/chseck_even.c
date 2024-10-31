#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long x = get_int("enter nuber : ");
    int count_of_num=1;
    for (int i=0; i<x; i++)
    {
        x= x/10;
        count_of_num++;
    }
    printf("count of nmber = %i\n",count_of_num);
    if (count_of_num%2 == 0)
    {
        printf("it's even\n");
    }
    else
    {
        printf("it's odde\n");
    }
   // printf("%i",x%2);
}
// 2 سكر + 4 شاى +صدور +روز+جبنه +مش