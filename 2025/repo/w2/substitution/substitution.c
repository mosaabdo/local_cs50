#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryption(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }

        for (int j = i + 1; j < 26; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    encryption(key);
    return 0;
}

void encryption(string key)
{
    string input = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, len = strlen(input); i < len; i++)
    {
        char c = input[i];
        if (islower(c))
        {
            printf("%c", tolower(key[c - 'a']));
        }
        else if (isupper(c))
        {
            printf("%c", toupper(key[c - 'A']));
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}