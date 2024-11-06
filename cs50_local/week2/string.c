#include<stdio.h>
#include<cs50.h>
#include <string.h> // this lib hav a same function of size_array
int size_array(string name);
int main(void)
{
    string name = get_string("name : ");
    for (int i = 0; i < size_array(name);i++)
    {
        printf("%c\n",name[i]);
    } 
}
void strngg (void)
{
 /* string and charcter
     what is string : string is array of the carchter 
    for exm : if you need print Hi
    i can tser 
        char h='H'; char i='i'
    but we have a best of the way
        string s="Hi";
*/
    // How i can make string in c
    char c[] = "c, string";
    //but in cs50
    string cs = "cs50, string";
    /* size of streng
    what size of string
    string = size of array +1
    +1 is enddecator of array it = 00000000;
    the enddecator prethent /0 or 00000000
    how i can take enddecator valu?
        you can use string[lenghs +1]
*/
    // printf("%s\n",cs);
    // printf("%s\n",c);
} 
int size_array(string name) // can replace this function by string,h lib : use __strlen__
{
    int n = 0;
    while(name[n] != '\0')
    n++;
    return n;
}

