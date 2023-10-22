#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "cs50.h"

#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./wordle wordsize\n");
        return 1;
    }
    int size = atoi(argv[1]);
    if (!(size >= 5 && size <= 8))
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8\n");
        return 1;
    }
    int tries = size + 1;
    printf("This is WORDLE50\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", tries, size);

    return 0;
}