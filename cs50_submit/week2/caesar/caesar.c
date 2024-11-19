#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h> 

void rotate(int key, string plaintext, char ciphertext[]);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;  
    }
    
    int kye = atoi(argv[1]);
    
    if (kye <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1; 
    }

    else 
    {
        for(int i = 0, l = strlen(argv[2]); i < l; i++)
        {
           if(argv[2][i] < 0 && argv[2][i] > 9)
           {
                printf("Usage: ./caesar key\n");
                return 1; 
           }
        }
    string text = get_string("add your text: ");
    char ciphertext[1000];  
    rotate(kye, text, ciphertext);
    printf("ciphertext: %s\n", ciphertext);
    return 0;
    }
}

void rotate(int key, string plaintext, char ciphertext[])
{
    key = key % 26; 
    int length = strlen(plaintext);

    for (int i = 0; i < length; i++)
    {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            ciphertext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
        }
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            ciphertext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
        }
        else
        {
            ciphertext[i] = plaintext[i]; 
        }
    }
    ciphertext[length] = '\0'; 
}
