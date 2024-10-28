#include<stdio.h>
#include<cs50.h>

int add (int a,int b);
int main (void)
{
    int x = get_int("Enter x : ");
    int y = get_int("Enter y : ");
    printf("x + y  = %i\n",add(x,y));
}
int add (int a,int b)
{
    return a+b;
}