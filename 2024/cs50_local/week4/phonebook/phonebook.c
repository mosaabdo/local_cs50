#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a"); //creat or open a phonebook.csv file and select open mode r,w,a

    char *name = get_string("Name  : ");
    char *number = get_string("Number: ");

    fprintf(file, "%s,%s\n", name, number); // add a new valu in phonebook file

    fclose(file);                          // close phonebook file

}