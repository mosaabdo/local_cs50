#include <cs50.h>
#include <stdio.h>

int bulder(int x);
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
int bulder(int x)
{
    for (int loop = 1; loop <= x; loop++)
    {
        for (int first_space = x; first_space > loop; first_space--)
        {   printf(" ");    }
        for (int first_block = 0; first_block < loop; first_block++)
        {   printf("#");    }
        printf("  "); 
        for(int sacnde_block = 0; sacnde_block < loop; sacnde_block++)
        {   printf("#");    }
        printf("\n");
    }
}