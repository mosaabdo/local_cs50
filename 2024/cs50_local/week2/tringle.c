#include <stdio.h>
#include <cs50.h>

bool checker (int a, int b, int c);
int main(void)
{
    printf("tntringle checker\n");
    printf("add size of dimention :- \n");
    float x = get_float("first dimantion  : ");
    float y = get_float("scande dimantion : ");
    float z = get_float("theard dimantion : ");

    bool r = checker(x, y, z);
    if(r == true)
    {
        printf("True\n");
        return 0;
    }
    else if(r == false)
    {
        printf("Not True!\n");
        return 1;
    }

}
bool checker (int a, int b, int c)
{
    if(a < 0 || b < 0 || c < 0)
    {
        return false;
    }
    if(a + b < c || a + c < b || c + b < a)
    {
        return false;
    }
    else
    {
        return true;
    }
}