#include <stdio.h>
#include <limits.h>
#include <cs50.h>

int sort(int a[], int l);
int main(void)
{
    int unsorted[] = {9, 11, 1, 4, 55, 0, 77, 8, 55, 45, 12, 78, 34, 56, 89, 23, 67, 90, 30, 44, 53, 77, 92, 14, 38, 61, 82, 29,63, 17, 86, 49, 71, 18, 25, 99, 6, 5};
    int length = sizeof(unsorted) /sizeof(unsorted[0]);
    int sorted[length];

    for(int i = 0; i < length; i++)
    {
        sorted[i] = sort(unsorted, length);
        printf("%i ",sorted[i]);
    }
    printf("\n");
    // 700   260 or 270 abo aubida;
}
int sort(int a[], int l)
{
    int min_index = -1; // لتخزين موقع أصغر عنصر
    int min_value = INT_MAX; // تعيين قيمة البداية لأكبر قيمة ممكنة

    // البحث عن أصغر عنصر
    for (int i = 0; i < l; i++)
    {
        if (a[i] < min_value)
        {
            min_value = a[i];
            min_index = i;
        }
    }

    // استبعاد أصغر قيمة بوضع قيمة كبيرة جدًا مكانها
    if (min_index != -1)
    {
        a[min_index] = INT_MAX;
    }

    return min_value; // إعادة أصغر قيمة
}