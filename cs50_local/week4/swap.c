#include <stdio.h>

void swap(int *a, int *p);
int main(void)
{
    int x = 1, y = 2;
    printf("x is %i, y is %i\n",x,y);
    swap(&x, &y);    
    printf("x is %i, y is %i\n",x,y);
}
void swap(int *a, int *p)
{
    int *tmp = *a;
    *a = *p;
    *p = tmp;   
}