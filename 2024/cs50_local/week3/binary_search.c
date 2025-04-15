#include <cs50.h>
#include <stdio.h>
const int MAX = 17;

// تعريف الدالة التي تقوم بالبحث الثنائي
int binary(int x[], int start, int end, int target);

int main(void)
{
    // مصفوفة مرتبة مسبقًا
    int arr[] = {1, 2, 3, 4, 5, 6, 12, 13, 14, 23, 56, 58, 77, 85, 122, 144, 211};
    int length = MAX;

    // إدخال الرقم المطلوب البحث عنه
    int target = get_int("Your number: ");

    // استدعاء دالة البحث الثنائي
    int result = binary(arr, 0, length - 1, target);

    // عرض النتيجة
    if (result != -1)
    {
        printf("Found at index %d\n", result);
    }
    else
    {
        printf("Not found\n");
    }
}

// تعريف دالة البحث الثنائي باستخدام الاستدعاء الذاتي (recursion)
int binary(int x[], int start, int end, int target)
{
    // إذا كانت بداية البحث تجاوزت النهاية، يعني أن العنصر غير موجود
    if (start > end)
    {
        return -1; // قيمة تشير إلى أن العنصر غير موجود
    }

    // إيجاد منتصف المصفوفة
    int mid = (start + end) / 2;

    // مقارنة العنصر الموجود في المنتصف مع الرقم المطلوب
    if (x[mid] == target)
    {
        return mid; // إذا كان الرقم موجودًا في المنتصف
    }
    else if (x[mid] > target)
    {
        // إذا كان الرقم المطلوب أصغر من الرقم في المنتصف، نبحث في النصف الأيسر
        return binary(x, start, mid - 1, target);
    }
    else
    {
        // إذا كان الرقم المطلوب أكبر من الرقم في المنتصف، نبحث في النصف الأيمن
        return binary(x, mid + 1, end, target);
    }
}
