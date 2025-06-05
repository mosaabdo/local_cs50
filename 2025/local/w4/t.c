#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = "Hi!";
    
    for(int i = 0, l= strlen(s); i < l; i++)
    {
        printf("%c\t%p\t%c\t\n", s[i], &s[i], *(s+i));
    }
}