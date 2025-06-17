#include <ctype.h>      // لدوال التعامل مع الأحرف مثل toupper
#include <stdbool.h>    // لتعريف نوع bool
#include <string.h>     // لدوال التعامل مع السلاسل مثل strcpy
#include <strings.h>    // لدالة strcasecmp (لمقارنة غير حساسة لحالة الأحرف)
#include <stdio.h>      // لدوال الإدخال/الإخراج مثل fopen و fscanf
#include <stdlib.h>     // لدالة malloc و free
#include "dictionary.h" // يحتوي على التعريفات المطلوبة من CS50

// تعريف بنية العقدة لكل كلمة
typedef struct node
{
    char word[LENGTH + 1];  // لتخزين الكلمة (بحد أقصى LENGTH)
    struct node *next;      // مؤشر للعقدة التالية (سلسلة مرتبطة)
} node;

// عداد عدد الكلمات التي تم تحميلها من القاموس
unsigned int word_count = 0;

// عدد خانات جدول التجزئة (buckets)
const unsigned int N = 1000;

// جدول التجزئة نفسه: مصفوفة مؤشرات لعُقد
node *table[N];

// دالة التجزئة (hash)
// تقوم بتحويل الكلمة إلى رقم (index) في جدول التجزئة
unsigned int hash(const char *word)
{
    unsigned int hash_value = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        // معامل 31 شائع في دوال التجزئة لتحسين التوزيع
        hash_value = (hash_value * 31 + toupper(word[i])) % N;
    }
    return hash_value;
}

// تحميل القاموس إلى الذاكرة
bool load(const char *dictionary)
{
    // افتح الملف
    FILE *dic = fopen(dictionary, "r");
    if (dic == NULL)
        return false;

    // تأكد من أن الجدول فارغ
    for (int i = 0; i < N; i++)
        table[i] = NULL;

    // مؤقت لتخزين الكلمات المقروءة من الملف
    char buffer[LENGTH + 1];

    // اقرأ الكلمات واحدة تلو الأخرى
    while (fscanf(dic, "%s", buffer) != EOF)
    {
        // احجز عقدة جديدة
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(dic);
            unload();  // حرر ما تم تحميله سابقًا
            return false;
        }

        // انسخ الكلمة إلى داخل العقدة
        strcpy(new_node->word, buffer);

        // احسب مؤشر جدول التجزئة
        int index = hash(buffer);

        // أدخل العقدة في بداية السلسلة المرتبطة في هذا المؤشر
        new_node->next = table[index];
        table[index] = new_node;

        // زِد عدد الكلمات
        word_count++;
    }

    fclose(dic);  // أغلق الملف
    return true;
}

// تحقق مما إذا كانت الكلمة موجودة في القاموس
bool check(const char *word)
{
    // احسب المؤشر المناسب للكلمة
    int index = hash(word);

    // امشي على السلسلة المرتبطة في هذا المؤشر
    node *cursor = table[index];
    while (cursor != NULL)
    {
        // استخدم strcasecmp لأنها لا تميز بين الأحرف الكبيرة والصغيرة
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true; // الكلمة موجودة
        }
        cursor = cursor->next; // انتقل للعقدة التالية
    }

    return false; // لم نجد الكلمة
}

// أرجع عدد الكلمات المحملة في القاموس
unsigned int size(void)
{
    return word_count;
}

// حرر كل الذاكرة المحجوزة للقاموس
bool unload(void)
{
    // امشي على كل الخانات في جدول التجزئة
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;     // خزّن العقدة الحالية
            cursor = cursor->next;  // انتقل للتالية
            free(tmp);              // حرر العقدة
        }
        table[i] = NULL; // اختياري: إفراغ المؤشر بعد التحرير
    }
    return true; // تم التحرير بنجاح
}
