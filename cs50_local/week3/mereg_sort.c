#include <stdio.h>

int merge(int sa[], int s, int e, int m);
int divide(int usa[], int S, int E);
int main(void)
{
    int unsorted[] = {9, 11, 1, 4, 55, 0, 77, 8, 55, 45, 12, 78, 34, 56, 89, 23, 67, 90, 30, 44, 53, 77, 92, 14, 38, 61, 82, 29,63, 17, 86, 49, 71, 18, 25, 99, 6, 5};
    int length = sizeof(unsorted) / sizeof(unsorted[0]);
    int start = 0, end = length -1;
    divide(unsorted, start, end);

    //add sorted aliment in unsorted array
    for (int i = 0; i < length; i++) 
    {
        printf("%i ", unsorted[i]);
    }
    printf("\n");
    return 0;

}
int divide(int usa[], int S, int E)
{
    // if this condtions is true > stop function.
    if(S >= E) 
        return 0;

    int M = (S+E)/2;
    // divide recurtion.
    divide(usa, S, M);
    divide(usa, M+1, E);
    // mereg divide almints.
    merge(usa, S, E, M);
}
int merge(int sa[], int s, int e, int m)
{
    int Lsize = m - s +1, Rsize = e - m;
    int Larry[Lsize], Rarray[Rsize];

    // full new array
    for(int i = 0; i < Lsize; i++)
        Larry[i] = sa[s + i];
    for(int j = 0; j <Rsize; j++)
        Rarray[j] = sa[m + 1 + j];

    //marge almint in same array
    int i = 0, j = 0, k = s;
    while(i < Lsize && j < Rsize)
    {
        if(Larry[i] <= Rarray[j])
            sa[k++] = Larry[i++];
            // i++; k++; <- thes is same sing thes -> sa[k++] = Larry[i++];
        else
            sa[k++] = Rarray[j++];
            // j++; k++;
    }
    // نسخ العناصر المتبقية في النصف الأيسر إذا كانت موجودة
    while (i < Lsize)
        sa[k++] = Larry[i++];

    // نسخ العناصر المتبقية في النصف الأيمن إذا كانت موجودة
    while (j < Rsize) 
        sa[k++] = Rarray[j++];
}