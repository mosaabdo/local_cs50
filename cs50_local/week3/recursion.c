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
    if(h > 0)
    {
        builder(h-1);
        for(int i = 0; i < h; i++)
        {
            printf("#");
        }
        printf("\n");
    }
   
}