#include <cs50.h>
#include <stdio.h> 
#include <string.h>

int normalize_key(int key);
void cipher_text(int key);

int main(int argc, string argv[])
{
    // Check command-line argument count
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Validate that key contains only digits
    string temp = argv[1];
    int key = 0, length = strlen(temp);
    
    for(int i = 0; i < length; i++)
    {
        if(temp[i] < '0' || temp[i] > '9')
        {
            printf("Usage: ./caesar key\n");
            return 2;
        } 
        key = key * 10 + (temp[i] - '0');    
    }
    
    // Verify key is positive
    if (key <= 0) 
    {
        printf("Key must be a positive integer\n");
        return 3;
    }   

    // Normalize key and encrypt text
    int normalized_key = normalize_key(key);
    cipher_text(normalized_key);

    return 0;
}

// Normalize key to be between 0-25
int normalize_key(int key)
{
    return key % 26;
}

// Encrypt and print text directly
void cipher_text(int key)
{
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    
    for(int i = 0, length = strlen(plaintext); i < length; i++)
    {
        char c = plaintext[i];
        
        if(c >= 'A' && c <= 'Z')
        {
            // Encrypt uppercase letters
            c = 'A' + (c - 'A' + key) % 26;
        }
        else if(c >= 'a' && c <= 'z')
        {
            // Encrypt lowercase letters
            c = 'a' + (c - 'a' + key) % 26;
        }
        // Non-alphabetic characters remain unchanged
        
        printf("%c", c);
    }
    printf("\n"); // New line at end
}