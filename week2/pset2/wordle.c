#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>
#include "cs50.h"

#define GREEN_BACKGROUND    "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW_BACKGROUND   "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED_BACKGROUND      "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET_BACKGROUND    "\e[0;39m"
#define GREEN_TEXT          "\033[32m"
#define YELLOW_TEXT         "\033[33m"
#define RED_TEXT            "\033[31m"
#define RESET_TEXT          "\033[0m"

void validate_input(int argc, const string argv[]);

int main(int argc, string argv[])
{
    validate_input(argc, argv);
    srand(time(NULL));
    int size = atoi(argv[1]);
    int tries = size + 1;
    printf("\n"GREEN_TEXT"*** This is WORDLE50 ***"RESET_TEXT"\n\n");
    printf("-> You have %i tries to guess the %i-letter word I'm thinking of...\n\n", tries, size);

    char filename[6];
    string extension = ".txt";
    snprintf(filename, sizeof(filename), "%d%s", size, extension);

    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    // store 1000 words, each containing max 10 chars (including \0 terminator)
    char words[1000][10];
    int word_count = 0;

    // read words in the file opened
    // fgets read a word and stores it into words[word_count]
    // fgets uses as separator the newline character \n
    while (fgets(words[word_count], sizeof(words[0]), file) != NULL) {
        // Remove the newline character from the end of each word and truncate the string
        // strcspn(words[word_count], "\n") finds the index of '\n'
        words[word_count][strcspn(words[word_count], "\n")] = '\0';
        word_count++;
    }
    fclose(file);
    int random_index = rand() % 1000;
    // Print the randomly selected word
    printf("Randomly selected word: %s\n", words[random_index]);

    return 0;
}

void validate_input(int argc, const string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./wordle wordsize\n");
        exit(1);
    }
    int input = atoi(argv[1]);
    if (!(input >= 5 && input <= 8))
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8\n");
        exit(1);
    }
}