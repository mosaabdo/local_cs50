#include <stdio.h>

#define  MAX 9

int main(void)
{
    int n;
    char c[MAX];

    printf("number: ");
    scanf("%i", &n);
   
    printf("string: ");
                     // scanf("%s", &c);  
    scanf("%s", c);// ed dont use ^&c^ becouse c is a pointer and insde c not have a valu but have a addresses
    
    printf("%s\n", c);
    printf("%i\n", n);
}