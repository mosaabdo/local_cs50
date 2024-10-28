#include <cs50.h>
#include <stdio.h>

int bulder(int x, int y);
int main(void)
{
    int hight;
    int space;
    do // this is for check while (condtions) of inpout
    {
        hight = get_int("Enter Hight : ");
        space = get_int("Enter Med Space : ");
    }
    while (hight < 1 && space < 1); // if inpuot not true return ask
    bulder(hight,space); // call in bulder function
}
int bulder(int x, int y)
{
    for (int loop = 1; loop <= x; loop++)
    {
        for (int first_space = x; first_space > loop; first_space--)
        {   printf(" ");    }
        for (int first_block = 0; first_block < loop; first_block++)
        {   printf("#");    }
        for (int med_space = 0; med_space < y; med_space++)
        {   printf(" ");  }
        for(int sacnde_block = 0; sacnde_block < loop; sacnde_block++)
        {   printf("#");    }
        printf("\n");
    }
}