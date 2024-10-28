#include <cs50.h>
#include <stdio.h>

void bulder(int x);
int main(void)
{
    int hight;
    do // this is for check while (condtions) of inpout
    {
        hight = get_int("Enter Hight : ");
    }
    while (hight < 1); // if inpuot not true return ask
    bulder(hight); // call in bulder function
}
void bulder(int x)
{
    for (int i = 1; i <= x; i++)
    {
        for (int s = x; s > i; s--)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}