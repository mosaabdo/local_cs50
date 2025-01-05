#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cs50.h>

void to_bin(void);
int main(void)
{
    printf("1] to binary\t2] to dcimel\n");
    int selected = get_int(">: ");

    if(selected == 1)
        to_bin();
    // else if(selected == 2)
    //     to_dis();
    else    
        return 1;
}
void to_bin(void)
{
    int input = get_int("Input a decimal number (0-255): ");
    if (input < 0 || input > 255)
    {
        printf("Invalid input! Please enter a number between 0 and 255.\n");
        return;
    }

    int binary[8] = {0}; // مصفوفة لتخزين البتات الثنائية

    // تحويل الرقم العشري إلى ثنائي
    for (int i = 7; i >= 0; i--)
    {
        binary[i] = input % 2; // احصل على البت الأخير
        input /= 2;           // قسّم الرقم على 2
    }

    // طباعة الناتج
    printf("Binary: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%d", binary[i]);
    }
    printf("\n");
}