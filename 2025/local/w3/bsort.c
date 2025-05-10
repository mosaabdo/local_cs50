#include <stdio.h>
#include <string.h>

int main(void)
{
    int unsorted[] = {1, 8, 6, 55, 10, 7, 2, 11, 32, 64, 50, 0, 88, 9};
    int length = sizeof(unsorted) / sizeof(unsorted[0]);

    for(int i = 0; i < length; i++)
    {
      
        if(unsorted[i] > unsorted[i+1])
        {
            int temp = unsorted[i+1];
            unsorted[i+1] = unsorted[i];
            unsorted[i] = temp; 
        }
    
    }
    for(int i = 0; i < length; i++)
    {
        printf("%d, ", unsorted[i]);
    }
    printf("\n");
    
    return 0;
}
