#include <stdio.h>
#include <cs50.h>

int sort(int us[], int l);
int main(void)
{
    int unsorted[] = {9, 11, 1, 4, 55, 0, 77, 8, 55, 45, 12, 78, 34, 56, 89, 23, 67, 90, 30, 44, 53, 77, 92, 14, 38, 61, 82, 29,63, 17, 86, 49, 71, 18, 25, 99, 6, 5};
    int lenth = sizeof(unsorted) / sizeof(unsorted[0]);
    int sorted[lenth];
    
    for(int i = 0; i < lenth; )
    {
        sorted[i] = sort(unsorted, lenth);
        lenth--;
        printf("%i ",sorted[i]);
    }printf("\n");
}
int sort(int us[], int l)
{
    int i = 0;
    for(i; i < l; i++)
    {
        if(i+1 != '\0')
        {
            if(us[i] > us[i+1])
            {
                int swap_place = us[i];
                us[i] = us[i+1];
                us[i+1] = swap_place;
            }
        }
    }
    return us[i];
}