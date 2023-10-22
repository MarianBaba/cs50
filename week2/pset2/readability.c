#include <stdio.h>
#include <string.h>
#include <math.h>
#include "cs50.h"

int main(void)
{
    string text = get_string("Text: ");
    int words = 0;
    int letters = 0;
    int sentences = 0;
    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        if (text[i] == 32 || text[i] == '\0')
        {
            words++;
        }
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    float average_letters = (letters / (float) words) * 100;
    float average_senteces = (sentences / (float) words) * 100;
    float coleman_liau_index = 0.0588 * average_letters - 0.296 * average_senteces - 15.8;
    int rounded = round(coleman_liau_index);

    if (rounded < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (rounded > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", rounded);
    }
}