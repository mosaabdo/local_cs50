#include <stdio.h>
#include <string.h>
#include <cs50.h>

void winer(int p1, int p2);
int letters(string input);
string upper(string lower); 
int scores (int s);
int main(void)
{
    string player1= get_string("First Player Input : ");
    string player2 = get_string("secande Player Input : ");
    
    // printf("i = %i\n",letters(player1));
    // printf ("score is : %i\n",scores(letters(player1)));
    // printf("score 1 is : %i",letters(player1));
    winer(letters(upper(player1)),letters(upper(player2)));
}
int letters(string input)
{
    char letter[26];
    int x = 0;
    for(int i = 65; i < 91; i++)
    {
        letter[x]= i;
        x++;
    }
    int s = 0;
    int r;
    int ret =0;
    for(int i = 0; s < strlen(input); i++)
    {
        for(;input[s] == letter[i];)
        {
            r = i;
            i = 0;
            s++;
            r = scores (r);
            ret = ret + r;
        }
    }
    return ret;
}
string upper(string lower) 
{
    for (int i = 0; i < strlen(lower);i++)
    {
        if (lower[i] >='a' && lower[i] <= 'z')
        {
          lower[i] = lower[i]-32;
        }
        else if(lower[i] >='A' && lower[i] <= 'Z')
        {
            lower[i] = lower[i];
        }
        else
        {
            lower[i] = 0;
        }
    }
        return lower;
}
int scores (int s)
{
    int score[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int rs = score[s];
    return rs;

}
void winer(int p1, int p2)
{
    if(p1 > p2)
    {
        printf ("Player 1 wins!\n");
    }
    else if (p1 < p2)
    {
        printf ("Player 2 wins!\n");
    }
    else

        printf ("Tie!\n");
}