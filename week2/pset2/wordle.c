#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
string get_word(string filename);
string get_guess(int word_size);
bool check_guess(string guess, string correct_word);

int main(int argc, string argv[])
{
    // input validation
    validate_input(argc, argv);

    // get cli param
    int size = atoi(argv[1]);
    int tries = size + 1;
    printf("\n"GREEN_TEXT"*** This is WORDLE50 ***"RESET_TEXT"\n\n");
    printf("-> You have %i tries to guess the %i-letter word I'm thinking of...\n\n", tries, size);

    // choose file from where to read
    char filename[6];
    string extension = ".txt";
    snprintf(filename, sizeof(filename), "%d%s", size, extension);
    
    // choose the word
    string correct_word = get_word(filename);
    printf("Randomly selected word: %s\n", correct_word);
    
    // for each try available, let the user guess
    int i;
    for (i = 0; i < tries; i++)
    {   
        // get guess from user (a ${size}-letter word)
        printf("Guess %i -> ", (i + 1));
        string guess = get_guess(size);

        // check guess has to: see if the guess is equal to the correct word, print the chars accondingly and return a boolean (has won or not)
        bool won = check_guess(guess, correct_word);
        if (won)
        {
            printf("\n\n"GREEN_BACKGROUND"Good guess! You got the word!"RESET_BACKGROUND"\n");
            break;
        }
    }
    if (i == tries)
    {
        printf("\n\n"RED_BACKGROUND"Sorry! You run out of tries!"RESET_BACKGROUND"\n");
    }
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

string get_word(string filename)
{
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

    // choose a random index
    srand(time(NULL));
    int random_index = rand() % 1000;

    // choose the word
    string correct_word = words[random_index];
    return correct_word;
}

string get_guess(int word_size)
{
    string guess;
    do
    {
        guess = get_string("Input a %d-letter word: ", word_size);
    } while (strlen(guess) != word_size);
    return guess;
}

bool check_guess(string guess, string correct_word)
{
    bool res = true;
    int len = strlen(guess);
    char colors[len];

    // Arrays to keep track of matched positions in both the guess and the correct word
    bool matched_guess[len];
    bool matched_word[len];

    for (int i = 0; i < len; i++) 
    {
        matched_guess[i] = false;
        matched_word[i] = false;
    }

    // First pass: check for characters in the correct position (green)
    for (int i = 0; i < len; i++) 
    {
        if (guess[i] == correct_word[i]) 
        {
            colors[i] = 'G';
            matched_guess[i] = true;
            matched_word[i] = true;
        }
    }

    // Second pass: check for characters in the correct word but in the wrong position (yellow)
    for (int i = 0; i < len; i++) 
    {
        if (!matched_guess[i]) 
        { // Skip characters already matched in the first pass
            for (int j = 0; j < len; j++) 
            {
                if (guess[i] == correct_word[j] && !matched_word[j]) 
                {
                    colors[i] = 'Y';
                    matched_guess[i] = true;
                    matched_word[j] = true;
                    break; // Exit the inner loop
                }
            }
        }
    }

    // Third pass: mark remaining unmatched characters as red
    for (int i = 0; i < len; i++)
    {
        if (!matched_guess[i]) 
        {
            colors[i] = 'R';
            res = false; // Set res to false if there are unmatched characters
        }
    }

    // Print characters with appropriate colors
    for (int i = 0; i < len; i++) 
    {
        if (colors[i] == 'G') 
        {
            printf(GREEN_TEXT"%c"RESET_TEXT, guess[i]);
        } 
        else if (colors[i] == 'Y') 
        {
            printf(YELLOW_TEXT"%c"RESET_TEXT, guess[i]);
        } 
        else if (colors[i] == 'R') 
        {
            printf(RED_TEXT"%c"RESET_TEXT, guess[i]);
        }
    }
    printf("\n");

    return res;
}
