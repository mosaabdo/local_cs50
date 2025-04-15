#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

void rotate(int key, string plaintext, char ciphertext[]);
int main(int argc, string argv[])
{
    if (argc != 2) // check  the argument if >2 or <2 print eror and return 1;
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++)  // loop for check input if it not num print error and retern 1;
    {

        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int kye = atoi(argv[1]);  // change the input from char to int
    if (kye <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string text = get_string("add your text: ");
    char ciphertext[1000]; //array for storge cipher text
    rotate(kye, text, ciphertext); // add data in function
    // printf("ciphertext: %s\n", ciphertext); // print return function
    printf("sucses\n");
    return 0;
}

void rotate(int key, string plaintext, char ciphertext[]) // finction for encreption text
{
    key = key % 26;  // the % for make kye >= 26
    int length = strlen(plaintext);

    for (int i = 0; i < length; i++)
    {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') // if char UPPER
        {
            ciphertext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A'; // add plain texit + key to chiper text and if totle > UPPER make totle % 26 for = UPPER
        }
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')    // if char lower..
        {
            ciphertext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';    //......
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[length] = '\0'; // after end loop make last value \0 to end array.
    FILE *file = fopen("cipher.txt", "a");
    fprintf(file,"%s\n",ciphertext);
    fclose(file);
}
