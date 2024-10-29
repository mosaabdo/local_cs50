#include<stdio.h>
#include <cs50.h>

void print (void);
float add(float x,float y);
float subtraction(float x, float y);
float multiplication(float x, float y);
float division(float x, float y);
int main (void)
{
    print();
    char typ =get_char("Your Choice : ");
    float first_n = get_float("Enter First Num : ");
    float Second_n = get_float("Enter Second Num : ");  
        if (typ == '+') 
            {add(first_n,Second_n);}
        else if (typ == '*') 
            {multiplication(first_n,Second_n);}
        else if (typ == '-') 
            {subtraction(first_n,Second_n);}
        else if (typ == '/') 
            {division(first_n,Second_n);}
        else
            {printf("Sorry\n");}
}
void print (void)
    {
        printf("-------------------------------------------------\n");
        printf("Chose Tyep Of Prosses\n");
        printf("+ ) to add              |  - ) to subtraction |\n");
        printf("* ) to multiplication   |  / ) to division    |\n");
        printf("-------------------------------------------------\n");
    }
float add(float x, float y)
    {
        printf("The Tottle is = [ %.3f", x+y);
        printf (" ]\n");
    }
float subtraction(float x, float y)
    {
    printf("The Tottle is = [ %.3f", x-y);
    printf (" ]\n");
    }
float multiplication(float x, float y)
    {
    printf("The Tottle is = [ %.3f", x*y);
    printf (" ]\n");
    }
float division(float x, float y)
    {
    printf("The Tottle is = [ %.3f", x/y);
    printf (" ]\n");
    }
