#include<stdio.h>
#include<cs50.h>

void meow (int n); 
int main (void)
{
   int counter = get_int("Enter Number : ");
   meow(counter);
}

void meow (int n) 
{ 
   for (;n > 0 ; n--)
   {
        printf("mewo\n");
   }
}
    