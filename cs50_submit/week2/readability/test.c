#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// تعريف الدوال
float words(string input);
float sentences(string input);
int algoritiihm(float L, float S);

int main(void)
{
    // المتغيرات
    float L = 0, S = 0;
    int grade;

    // طلب النص من المستخدم
    string text = get_string("Add your text: ");

    // حساب متوسط الأحرف والجمل
    L = words(text);
    S = sentences(text);

    // حساب المستوى الدراسي
    grade = algoritiihm(L, S);

    // الطباعة
    printf("The Words Average is    : %.2f\n", L);
    printf("The Sentences Average is: %.2f\n", S);
    if (grade < 1)
    {
        printf("Grade: Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade: 16+\n");
    }
    else
    {
        printf("Grade: %i\n", grade);
    }
}

// دالة حساب متوسط الأحرف لكل 100 كلمة
float words(string input)
{
    int letters = 0, words = 1;

    for (int i = 0; i < strlen(input); i++)
    {
        if (isalpha(input[i]))
        {
            letters++;
        }
        else if (input[i] == ' ')
        {
            words++;
        }
    }

    return ((float)letters / words) * 100;
}

// دالة حساب متوسط الجمل لكل 100 كلمة
float sentences(string input)
{
    int words = 1, sentences = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            words++;
        }
        else if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentences++;
        }
    }

    return ((float)sentences / words) * 100;
}

// دالة حساب مؤشر القراءة
int algoritiihm(float L, float S)
{
    return round(0.0588 * L - 0.296 * S - 15.8);
}
