#include <stdio.h>
#include <cs50.h>

void loop(int x);
int main(void)
{
    int input;
    do{
    input = get_int("Enter Rebet Time : ");
    loop(input);
    }while(input < 1);
}
void loop(int x)
{
    for(int i=0; i<x; i++)
    printf("###\n");
}