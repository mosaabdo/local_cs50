#include <stdio.h>
#include <cs50.h>

int buldeer (int x);
int main (void)
{
    int hight;
    do
    {
      hight = get_int("Enter Hight : ");
    } while (hight < 1);
    
    buldeer(hight);
}
int buldeer (int x)
{
    for (int i = 1; i <= x; i++)
    {
        for(int j = 0;j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
