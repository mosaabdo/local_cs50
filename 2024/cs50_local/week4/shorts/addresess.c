#include <stdio.h>
#include <stdlib.h>

void file(int input);
int addr(int *x);
int main(void)
{
    int x = 0;
    x = addr(&x);
    file(x);    
}
int addr(int *x)
{
    printf("x: ");
    scanf("%i", x);
    return *x;
}
void file(int input)
{
    FILE *f = fopen("addresess.txt", "a");
    fprintf(f, "%i, %i\n", input, &input);
    fclose(f);
}