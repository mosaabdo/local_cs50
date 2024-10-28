#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char x = get_char ("re you agrre ");
    
    if (x == 'y' || x == 'Y')
      {printf("your agreeded\n");}
    else if (x == 'n' || x == 'N')
      {printf("your not agreeded\n");}
    else 
     {printf ("sorry tray again\n");}
    

}