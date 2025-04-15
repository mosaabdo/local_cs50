#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int arr[] = {1, 9, 3, 5, 4, 6, 44, 22, 0, 234, 64, 023, 55, 2};
    int input = get_int("add your number : ");
    
    // LINER SEARCH 
    int length = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < length; i++)
    {
        if(input == arr[i])
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}