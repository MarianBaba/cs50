#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "cs50.h"

bool only_digits(string s);

int main(int argc, string argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]) % 26;
    string plaintext = get_string("Plaintext:  "); 
    // lowercase ascii values: from 97 ('a') to 122 ('z')
    // uppercase ascii values: from 65 ('A') to 90 ('Z')
    printf("Ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if ((plaintext[i] >= 65 && plaintext[i] <= 90) || (plaintext[i] >= 97 && plaintext[i] <= 122)) {
            int base = islower(plaintext[i]) ? 97 : 65;
            int shift = (((plaintext[i] % base) + key) % 26);
            plaintext[i] = base + shift;
        }
        printf("%c", plaintext[i]);
    }
    printf("\n");
    return 0;
}

bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!(s[i] >= 48 && s[i] <= 57))
        {
            return false;
        }
    }
    return true;
}