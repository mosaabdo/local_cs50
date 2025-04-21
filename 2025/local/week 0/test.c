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
    while (hight < 1 || hight > 8); // if inpuot not true return ask
    bulder(hight); // call in bulder function
}
void bulder(int x)
{
    for (int i = 1; i <= x; i++)
    {
        for (int first_space = x; first_space > i; first_space--)
            printf(" ");
        for (int first_block = 0; first_block < i; first_block++)
            printf("#");
        
        printf("  ");
        for (int first_block = 0; first_block < i; first_block++)
            printf("#");
        printf("\n");
    }
}