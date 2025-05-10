#include <stdio.h>
#include <string.h>

int main(void)
{
    int unsorted[] = {1, 8, 6, 55, 10, 7, 2, 11, 32, 64, 50, 0, 88, 9};
 
    int length = sizeof(unsorted) / sizeof(unsorted[0]);

    for(int i = 0, u = 0; i < length; i++)
    {
        int j = 0 + u;
        for(; j < length; j++)
        {
            if(unsorted[i] > unsorted[j])
            {
                int temp = unsorted[j];
                unsorted[j] = unsorted[i];
                unsorted[i] = temp;
            }
        }
        printf("%d, ", unsorted[i]);
        u++;
       
    }
    printf("\n");

    return 0;
}
