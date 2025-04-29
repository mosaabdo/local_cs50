#include <cs50.h>
#include <stdio.h>
#include <string.h>

int calc(string input);
void grade(int result);
int main(void)
{
    string text = get_string("Text");
    int calc_grade = calc(text);
    grade (calc_grade);

    return 0;
}
int calc(string input)
{
   
    printf("You entered: %s\n", input);
    return 0;
}
void grade(int result)
{

}