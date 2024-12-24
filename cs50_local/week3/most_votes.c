#include <stdio.h>
#include <cs50.h>

typedef struct
{
    string name;
    int votes;
}
candidate;
const int MAX = 3;

void box(int x);
int main (void)
{
    printf("slect prosses\n1] first one\t2] med one\t3] last one\n");
    int slected = get_int("> ");
    box(slected);

    
}
void box(int x)
{
    candidate prisdint[MAX];
    prisdint[0].name = "mousa";
    prisdint[0].votes = 8;
    prisdint[1].name = "ahmed";
    prisdint[1].votes = 6;
    prisdint[2].name = "hasan";
    prisdint[2].votes = 2;

    //compear
   

    // resolt
    if(x == 1)
    {
    int v = 1, index = 0;
    for(int i = 0; i < MAX; i++)
    {
        if(index < MAX-1)
        {
            if(prisdint[index].votes < prisdint[index+v].votes)
            {
                index++;
            }
            else
            {
                v++;
            }
        }
    }
        printf("The First one is %s\n", prisdint[index].name);
        printf("%s have a %i votes\n", prisdint[index].name, prisdint[index].votes);
    }
    else if( x == 2)
    {
        printf("Not Avalible Now!\n");
    }
    else if( x == 3)
    { 
        int v = 1, index = 0;
        for(int i = 0; i < MAX; i++)
        {
            if(index < MAX-1)
            {
                if(prisdint[index].votes > prisdint[index+v].votes)
                {
                    index++;
                }
                else
                {
                    v++;
                }
            }
        }
        printf("The last one is %s\n", prisdint[index].name);
        printf("%s have a %i votes\n", prisdint[index].name, prisdint[index].votes);
    }
    else
        printf("Error Nor True Slected\n");
}

