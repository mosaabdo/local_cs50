#include<stdio.h>
#include <cs50.h>

void print (void);
int add(int x,int y);
float subtraction(float x, float y);
int multiplication(int x, int y);
float division(float x, float y);
int main (void)
{
    print();
    char typ =get_char("Your Choese : ");
    int first_n = get_float("Enter First Num : ");
    int sacnde_n = get_float("Enter Sacend Num : ");  
        if (typ == '+') 
            {add(first_n,sacnde_n);}
        else if (typ == '*') 
            {multiplication(first_n,sacnde_n);}
        else if (typ == '-') 
            {subtraction(first_n,sacnde_n);}
        else if (typ == '/') 
            {division(first_n,sacnde_n);}
        else
            {printf("Soory\n");}
}
void print (void)
{
    printf("-------------------------------------------------\n");
    printf("Chose Tyep Of Prosses\n");
    printf("+ ) to add              |  - ) to subtraction |\n");
    printf("* ) to multiplication   |  / ) to division    |\n");
    printf("-------------------------------------------------\n");
}
int add(int x, int y)
{
    printf("The Tottle is = [ %i", x+y);
    printf (" ]\n");
}
float subtraction(float x, float y)
{
   printf("The Tottle is = [ %.3f", x-y);
   printf (" ]\n");
}
int multiplication(int x, int y)
{
   printf("The Tottle is = [ %i", x*y);
   printf (" ]\n");
}
float division(float x, float y)
{
   printf("The Tottle is = [ %.3f", x/y);
   printf (" ]\n");
}
