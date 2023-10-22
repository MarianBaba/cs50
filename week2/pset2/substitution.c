#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

int main(int argc, string argv[])
{
    // input validation
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    string key = argv[1];

    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if ((plaintext[i] >= 65 && plaintext[i] <= 90) || (plaintext[i] >= 97 && plaintext[i] <= 122)) {
            int base = islower(plaintext[i]) ? 97 : 65;
            if (base == 97)
            {
                plaintext[i] = tolower(key[plaintext[i] - base]); 
            }
            else
            {
                plaintext[i] = toupper(key[plaintext[i] - base]); 
            }
        }
        printf("%c", plaintext[i]);
    }
    printf("\n");

    return 0;
}