#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    int n = 50;         // just var..
    int *p = &n;        // pointer have a addres of n

    //  char *name == string name
    string s = "Hi!";
    char *ss = "Bay!";
    
    printf("n = %i\n",n);
    
    *p = 10;            // change valu in this addres 
    
    printf("%s\n",s);
    printf("s addres started in, %p\n",&s); // print wher s pointer started in memory

    for (int i = 0, lenth = strlen(s); i < lenth; i++) // thes loop for print char and addresses insded s
    {
        printf("%c, ",s[i]);
        printf("%p",&s[i]);
        printf("\n");
    }

    printf("s addres end in, %p\n",&s[strlen(s)]); // print wher s pointer ended in memory
    printf("%p\n",&n);  // print var... n addres
    printf("%p\n",p);   // print the addres insade thes varuable
    printf("after update n = %i\n",*p);  // Go to thes addres and show me what is insade it.

    printf("%s\n",ss);
}