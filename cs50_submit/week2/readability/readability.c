#include <string.h>
#include <stdio.h>
#include <cs50.h>

float words (string input);
float sentences (string input);
void algorithim (float L, float S);
int main (void)
{
    float L = 0, S = 0;
    int gread = 0;
    string text = get_string("add your text : ");
    L = words(text);
    S = sentences(text);
    algorithim(L, S);
}

float words (string input)
{
    int letters = 0, word = 1, length = strlen(input);

    for (int i = 0; i < length; i++)
    {
        if (word >=100)
        {
            break;
        }
        else if (input[i] == ' ')
        {
            word++;
        }
        else
        {
            letters++;
        }
    }

    return ((float)letters / word) * 100;
}

float sentences (string input)
{
    int word = 0, sentence = 0, length = strlen(input);

    for (int i = 0; i < length; i++)
    {
        if (input[i] == ' ')
        {
            word++;
        }
        else if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentence++;
        }
    }

    return ((float)sentence / word) * 100;
}

void algorithim (float L, float S)
{
    int index = 0.0588 * L - 0.296 * S - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
