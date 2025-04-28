#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


void winner_status(int p1, int p2);
int compare(string input);
int main(void)
{
    string p_1_input = get_string("Plyer 1: ");
    string p_2_input = get_string("Plyer 2: ");

    int point_p_1 = compare(p_1_input);
    int point_p_2 = compare(p_2_input);

    winner_status(point_p_1, point_p_2);

    return 0;
}
int compare(string input)
{   // make point arry
    char c_point [26];
    for(int i = 0; i < 26; i++)
        c_point[i] = 'A' + i;
    int p_point[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // change letter casce to upper
    int  length = strlen(input);
    char temprorry[length+1];
    for (int i = 0; i < length; i++)
        temprorry[i] = toupper(input[i]);
    temprorry[length] = '\0';

    // calc pointes
    int sum = 0;
    for(int i = 0; i < length;i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(temprorry[i] == c_point[j])
            {
                sum = sum + p_point[j];
                break;
            }
        }   
    }

    return sum;
}

void winner_status(int p1, int p2)
{
    if (p1 > p2)
        printf("Player 1 is Winner\n");
    else if( p1 < p2)
        printf("Player 2 is Winner\n");
    else
        printf("Tie\n");
}
