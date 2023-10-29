#include <stdio.h>
#include <string.h>
#include "cs50.h"

#define MAX 9

typedef struct
{
    string name;
    int votes;
} candidate;

int main(int argc, string argv[])
{
    if (argc + 1 > MAX)
    {
        printf("The maximum number of candidates possible is %d", MAX);
        return 1;
    }

    candidate candidates[argc - 1];

    for (int i = 1; i < argc; i++)
    {
        candidates[i - 1].name = argv[i];
        candidates[i - 1].votes = 0;
    }

    int voters = get_int("Nummber of voters: ");

    for (int i = 0; i < voters; i++)
    {
        string candidate = get_string("Vote: ");
        for (int i = 0; i < argc - 1; i++)
        {
            if (strcmp(candidate, candidates[i].name) == 0)
            {
                candidates[i].votes++;
            }
        }
    }

    int index_winner = 0;
    for (int i = 1; i < argc - 1; i++)
    {
        if (candidates[i].votes > candidates[index_winner].votes)
        {
            index_winner = i;
        }
    }

    printf("%s\n", candidates[index_winner].name);
    
}