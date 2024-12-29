#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");
    /*
    if(*s == *t)  this line = if(strcmp(s,t) == 0) 
    *s == *t  is a copmare valeu in this addresses.
    But!
    the compare will be a first char from string
    for exm :
        s: Hi
        t: Hah
        same
    for that we need a loop for check all array
    */ 
   // compare loop
    bool same = false;
    while (*s != '\0' || *t != '\0')
    {
        if(*s++ == *t++) 
            same = true;
        else
            same = false; *s = '\0';
    }
    // check status
    if(same == true) 
        printf("Same\n");
    else
        printf("Diffrent\n");
}