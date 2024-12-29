#include <stdio.h>
#include <ctype.h>
#include <cs50.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = s; // this syntax will be copy var address from s to t, for that any edit insde t will be applayd in s.
    
    t[0] = toupper(s[0]);
    printf("t: %s\n",t);
    printf("s: %s\n",s);
}