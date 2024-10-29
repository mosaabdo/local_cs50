#include <cs50.h>
#include <stdio.h>

int main()
{
    int cash,in_cash;
    do {
        cash = get_int("Change owed : ");
    }   while (cash < 1);
    if (cash <= 5 || cash == 10 || cash == 25)
    {   printf("You Need %i Prossece\n",cash);}
    in_cash = cash;
    int max, hight, med, low, tottle;
    max = hight = med = low = tottle = 0;

    for(;cash >= 25; cash-=25)
        { max++; }
    for(;cash >= 10; cash-=10)
        { hight++; }
    for(;cash >= 5; cash-=5)
        { med++; }
    for(;cash >= 1; cash-=1)
        { low++; }
    tottle = max+hight+med+low;
    printf("You Need %i Prossece\n", tottle);
    printf("Tootle = %i x[25] + %i x[10] + %i x[5] + %i x[1] = %i = [%i]\n",max,hight,med,low,tottle,in_cash);

}
