#include <stdio.h>
#include <cs50.h>

int buldeer (int x,int y);
int main (void)
{
    int culom = get_int("Enter Hight : ");
    int rose = get_int("Enter Width : ");
    buldeer(culom,rose);
}
int buldeer (int x, int y)
{
    for (; x > 0; x--)
    {
        int r = y;
        while ( r > 0)
        {
            printf("#");
            r--;
        }
        printf("\n");
    }
}
