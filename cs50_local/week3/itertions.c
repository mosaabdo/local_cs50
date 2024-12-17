#include<stdio.h>
#include<cs50.h>

void builder (int h);
int main(void)
{
    int hight = get_int("Hight : ");
    builder(hight);

}
void builder (int h)
{
    for(int i = 1; i < h+1; i++)
    {
        for(int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}