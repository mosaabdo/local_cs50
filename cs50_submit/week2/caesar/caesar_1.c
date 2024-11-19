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

string rotate(int key, string plaintext)
{
    key = key % 26; 
    int length = strlen(plaintext);
    char ciphertext[length + 1];

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
    return strdup(ciphertext); 
}
