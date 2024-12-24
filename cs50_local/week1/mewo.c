#include<stdio.h>
#include<cs50.h>

void meow (void); //this line for define mewo function => look line 15  
int main (void)
{
   int counter = get_int("Enter Number : ");
//    int i = 0; >>     while (i < counter ) >>{printf....; i++;}
    while (counter > 0)
    {
        meow();
        counter--;
    }
}
void meow (void)
{
        printf("mewo\n");
}
    