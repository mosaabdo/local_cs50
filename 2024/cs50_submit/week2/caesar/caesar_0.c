#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

string rotate(int key, string plaintext);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
    }
    else
    {
        int kye = atoi(argv[1]); 
        if (kye > 0)
        {   
            string text = get_string("add your text : ");
            printf("%s\n",rotate(kye, text));
        }
        else
        {
            printf("Usage: ./caesar key\n");
        }
    }

}
string rotate(int kye, string plaintext)
{
    string ciphertext = plaintext;
    int length = strlen(plaintext);

    for(int i = 0; i < length; i++)
    {
        if(plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            ciphertext[i] = plaintext[i]+kye;
        }
        else if(plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            ciphertext[i] = plaintext[i]+kye;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    return ciphertext;
}