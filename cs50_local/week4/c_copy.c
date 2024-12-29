#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <cs50.h>

int main(void)
{
    char *s = get_string("s: ");

     if(s == NULL)  // check memory if not have engf memory end program
        return 1;

    int length = strlen(s);

    char *t = malloc(length+1); // search an a free space in memory for creat new array

    if(t == NULL)   // check memory if not have engf memory end program
        return 1;

    strcpy(t, s);   // just for copy  elmint from s to t

    if(length > 0)  
        t[0] = toupper(s[0]);

    printf("t: %s, ",t);
    printf("%p\n",t);
    printf("s: %s, ",s);
    printf("%p\n",s);

    free(t);      // free t space after ended use t
    return 0;
}