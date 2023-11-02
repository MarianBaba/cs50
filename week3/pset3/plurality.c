#include <stdio.h>
#include <string.h>
#include "cs50.h"

#define MAX 9

typedef struct
{
    string name;
    int votes;
} 
Candidate;

bool is_valid(int len, string candidate, Candidate candidates[]);

int main(int argc, string argv[])
{
    if (argc + 1 > MAX)
    {
        printf("The maximum number of candidates possible is %d", MAX);
        return 1;
    }

    Candidate candidates[argc - 1];

    for (int i = 1; i < argc; i++)
    {
        candidates[i - 1].name = argv[i];
        candidates[i - 1].votes = 0;
    }

    int voters = get_int("Number of voters: ");

    for (int i = 0; i < voters; i++)
    {
        string candidate;
        do
        {
            candidate = get_string("Vote: ");    
        } while (!is_valid(argc - 1, candidate, candidates));
        
        for (int i = 0; i < argc - 1; i++)
        {
            if (strcmp(candidate, candidates[i].name) == 0)
            {
                candidates[i].votes++;
            }
        }
    }

    int max_votes = 0;
    for (int i = 0; i < argc - 1; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    for (int i = 0; i < argc - 1; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s ", candidates[i].name);
        }
    }

    printf("\n");
}

bool is_valid(int len, string candidate, Candidate candidates[])
{
    bool found = false;
    for (int i = 0; i < len; i++)
    {
        if (strcmp(candidate, candidates[i].name) == 0)
        {
            found = true;
        }
    }
    if (!found)
    {
        printf("Invalid vote.\n");
    }
    return found;   
}