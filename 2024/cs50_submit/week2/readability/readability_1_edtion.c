#include <stdio.h>
#include <cs50.h>
#include <string.h>

float words (string input);
float sentences (string input);
int algurithim (float L, float S);
int main (void)
{
    float L = 0, S = 0;
    float gread;
    string text = get_string("add your text : ");
    L = words(text);
    S = sentences(text);
    gread = algurithim(L, S);
    
    printf("The Words Avrage is    : %f\n",L); 
    printf("The Sentences Avrage is    : %f\n",S); 
    printf("The Gread  is          : %i\n",gread); 
   

}
float words (string input)
{
   char w_array[100][15];
   char bufer[15];
   int num_of_word = 0, pos_of_word = 0, bl = 0, length_of_input = strlen(input);
   
   for (int i = 0; i <= length_of_input; i++)
    {
       if(input[i] == ' ' || input[i] == '\0')
       {
            if(pos_of_word > 0)
            {
                bufer[pos_of_word] == '\0';
                for (int j = 0; j <= pos_of_word; j++)
                {
                    w_array[num_of_word][j] = bufer[j];
                }
                num_of_word++;
                if (num_of_word >= 100)
                {
                    break;
                }
                pos_of_word = 0;
            }
       }
       else 
       {
            bufer[pos_of_word] = input[i];
            pos_of_word++;
            bl++;
       }
    }

    float L = ((float)bl / (float)num_of_word) *100;
    return L;
}
float sentences (string input)
{
    int length = strlen(input), spaces = 0, sentence = 0, n_word = 0;
    float S = 0;
    for (int i = 0; i < length; i++)
    {
        if (spaces >= 99)
        {
            break;
        }
        else if (input[i] == ' ')
        {
            spaces++;
        }
        else if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentence++;
        }
    }
    if(length == 0)
    {
        n_word = 0;
    }
    else
    {
        n_word = spaces+1;
    }

    S = ((float)n_word / (float)sentence) *100;
    return S;
}
int algurithim (float L, float S)
{
    int index;
    index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}