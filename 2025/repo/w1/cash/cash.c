#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int input;
    do{
        
        input = get_int("Change Owed : ");

    }while (input < 1);
    

    int list_arr[] = {25, 10, 5, 1};
    int ar_size = sizeof(list_arr) / sizeof(list_arr[0]);
    int x = 0;
    
    for(int i = 0; i < ar_size; i++)
    {
        if(input >= list_arr[i])
        {
            input = input - list_arr[i];
            i--;x++;
        }
    }
    printf("%i\n", x);

    return 0;
}