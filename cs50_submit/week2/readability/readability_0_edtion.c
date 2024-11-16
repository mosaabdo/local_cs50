#include <stdio.h>
#include <cs50.h>
#include <string.h>

int letter (string inpu);
int main (void)
{
    string text = get_string("Add The Text : ");
    letter(text);
}
int letter (string inpu)
{
    int spaces = 0, sentences = 0; 
    int length =  strlen(inpu);
    for (int i = 0; i < length; i++)
    {
        if (inpu[i] == ' ')
        {
            spaces++;
        }
        else if (inpu[i] == '!' || inpu[i] == '.'|| inpu[i] == '?')
        {
            sentences++;
        }
    }
    int letters = length - spaces, words = 0; 
    if (length == 0)
    { 
        words = 0;

    }
    else if (words < 99) 
    {
        words = 100;
    }
    else
    {
        words = spaces +1;
    }   
        
    printf("L is %i\n  is %i\nW is %i\nS is %i\n",letters,spaces,words,sentences);
    //avrge
    int avrge = letters / words;
    printf("%i\n",avrge);
}
