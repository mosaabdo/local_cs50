#include <stdio.h>
#include <cs50.h>
#include <string.h>

/*
toupper():
    this function from string lib included in <ctype.h> == my function upper 
tolower();
    this function from string lib included in <ctype.h> == my function lower
*/ 

char lower(string ix);
char upper(string ix);
int main (void)
{
    int input_process;  
    string input_text = get_string("Your Word : ");
    printf("[1] TO UPPER        [2] to lower\n"); 
    do{
        input_process = get_int("select process type : ");
        if (input_process == 1)
            upper(input_text);
        else if (input_process == 2)
            lower(input_text);
    } while (input_process < 1 || input_process > 2);
}

char lower(string ix) // +32   and can use tolower() from <ctype.h>
{
    for (int i = 0; i < strlen(ix);i++)
    {
        if (ix[i] >='a' && ix[i] <= 'z')
        {
            printf("%c",ix[i]);
        }
        else if(ix[i] >='A' && ix[i] <= 'Z')
        {
           printf("%c",ix[i]+32);
        } else
        {
            printf("%c",ix[i]);
        }
    }   printf("\n");
}
char upper(string ix) // -32   and can use toupper() from <ctype.h>
{
    for (int i = 0; i < strlen(ix);i++)
    {
        if (ix[i] >='a' && ix[i] <= 'z')
        {
           printf("%c",ix[i]-32);
        }
        else if(ix[i] >='A' && ix[i] <= 'Z')
        {
            printf("%c",ix[i]);
        } else
        {
            printf("%c",ix[i]);
        }
    }   printf("\n");
}