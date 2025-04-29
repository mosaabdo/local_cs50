#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int calc(string input);
void grade(int result);
int main(void)
{
    string text = get_string("Text: ");
    int calc_result = calc(text);
    grade (calc_result);

    return 0;
}
int calc(string input)
{
    int letters = 0, word = 0, sentences = 0;
    char temp;

    for(int i = 0, length = strlen(input); i < length; i++)
    {
        temp = toupper(input[i]);
        if(word > 100)
            break;
        if(temp >= 'A' && temp <= 'Z')
            letters++;
        if(temp == ' ' && input[i - 1] != ' ')
            word++;
        if(temp == '.' || temp == '!' || temp == '?')
            sentences++;
    }

    if(word == 0) return 0;
    if(letters > 0) word++;
    double L =(letters * 100.0) / word;
    double S =(sentences * 100.0) / word;
    return round(0.0588 * L - 0.296 * S - 15.8);

}
void grade(int result)
{
    if(result <= 1)
        printf("Before Grade 1\n");
    else if(result < 16)
        printf("Grade %d\n", result);
    else
        printf("Grade 16+\n");
}
