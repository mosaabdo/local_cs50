#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct 
{
    string name;
    string number;
}   persion;

void add_pepole(persion pepole);
int main(void)
{
    persion pepole;

    int choice = get_int("1] search conect\t2] add conect\n : ");
    if(choice == 1)
    {
        printf("coming son\n");
        return 0;
    }
    else if(choice == 2)
    {
        add_pepole(pepole);
        return 0;
    }
    else if(choice != 1 || choice != 2)
    {
        printf("unviled choice\n");
        return 1;
    }

}
void add_pepole(persion pepole)
{
    pepole.name = get_string("Name is: ");
    pepole.number = get_string("Number is: ");

    printf("add your :-\n%s\t%s\n",pepole.name, pepole.number);
}