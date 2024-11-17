#include <stdio.h>
#include <string.h>
#include <cs50.h>

int sentences(string input);
int words(string input);

int main(void)
{
    int w = 0, s = 0;
    string input = get_string("add your text : ");
    w = words(input);
    s = sentences(input);
    printf ("num of words is     : %i\n",w);
    printf ("num of sentences is : %i\n",s);

}

int words(string input)
{
    int spaces = 0, num_w, letters = 0, length = strlen(input);
    
    if (length == 0)
        num_w = 0;
    else
        num_w = 1;
        
    for (int i = 0; i < length; i++)
    {
        if (input[i] == ' ')
        {
            spaces++;
            num_w++;
        }
        else
        {
            letters++;
        }
    }
    return num_w;
}

int sentences(string input)
{
    int num_w = 0, num_s = 0, length = strlen(input);

    for (int i = 0; i < length; i++)
    {
        if (input[i] == ' ')
            num_w++;
        else if (input[i] == '.' || input[i] == ',')
            num_s++;
    }
    return num_s;
}