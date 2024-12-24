#include <stdio.h>
#include <cs50.h>

int collazt(int n, int steps);
int main(void)
{
    int input = get_int("add collazit number : ");
    int steps = 0;
    int x = collazt(input, steps);
    printf("the steps is %i times.\n",x);
}
int collazt(int n, int steps)
{
    if(n == 1)
        return steps;
    else if(n % 2 == 0)
    {
        steps++;
        collazt(n/2, steps);
    }
    else
    {
        steps++;
        collazt(3*n+1, steps);
    }
}