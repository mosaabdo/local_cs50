#include <stdio.h>
#include <cs50.h>
// prototype
float avrge(int length);
string guid(int i);
void print(void);
int main(void)
{
    const int NUMBER = 3;
    // call function
    print();
    printf("The Avrge is : %.2f\n",avrge(NUMBER));
}
void print (void)
{
    printf("################\n");
    printf("##### Avrge ####\n");
    printf("################\n");
}
float avrge(int length)
{
    // take the array length
    float score[length]; // array in c way is : float c[] = valu;
    float sum_avrge = 0;
    for(int i=0; i<length; i++)
    {
        // for check input do-while
        do{ 
        // get array[x] valu from user
        score[i] = get_float("Enter Score of %s : ",guid(i));
        // calculat avreg
        sum_avrge += score[i];
        }while (score[i]<1);
    }
    // return avrge valu
    return sum_avrge/(float)length;
}
string guid(int i)
{
    string m[]={"Math","Computer","languge"};
    return m[i];
}
