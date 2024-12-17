#include<stdio.h>
#include<string.h>
#include<cs50.h>

typedef struct  // *! define strcut
{
    string name;
    string number;
}   
person;     // *! name of strcut
const int MAX = 4;

int main (void)
{
    person people[MAX];
    people[0].name = "mousa", people[0].number = "+201001234";
    people[1].name = "ahmed", people[1].number = "+201101234";
    people[2].name = "kaled", people[2].number = "+201201234";
    people[3].name = "hassn", people[3].number = "+201501234";
    
    string input = get_string("add name or number :-\n");
    for (int i = 0; i < MAX; i++)
    {
        if(strcmp(people[i].name,input) == 0)
        {
            printf("%s\n",people[i].number);
            return 0;
        }
        else if(strcmp(people[i].number,input) == 0)
        {
            printf("%s\n",people[i].name);
            return 0;
        }
    }
    printf("\aNot Found\n");
    return 1;

}
