#include <stdio.h>

void input(void);
int main(void)
{
    input();
    return 0;
}
void input(void)
{
    while (1)
    {
        int n;
        printf("n: ");
        if (scanf("%i", &n) == 1)
        {
            printf("n: %i\n", n);
            break;  // إدخال صحيح، نخرج من اللوب
        }
        else
        {
            printf("Invalid input. Please enter an integer.\n");

            // تنظيف البافر من أي إدخال خاطئ
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
}