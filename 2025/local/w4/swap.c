#include <stdio.h>

void swap(int *a, int *b);
int main(void)
{
    int x = 1, y = 2;

    printf("Before:\tx = %d\ty = %d\n", x, y);
    swap(&x, &y);
    printf("After :\tx = %d\ty = %d\n", x, y);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}