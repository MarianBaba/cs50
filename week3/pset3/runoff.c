#include "cs50.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    int votes;
    bool is_eliminated;
}
Candidate;

// usage: ./runoff Alice Bob Charlie David -> argc = 5, so candidates are 4 (argc - 1)
int main(int argc, string argv[])
{
    int number_of_candidates = argc - 1;
    Candidate candidates[number_of_candidates];
    for (int i = 0; i < number_of_candidates; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].is_eliminated = false; 
    }

    // loop for printing all the candidates array
    /* for (int i = 0; i < number_of_candidates; i++)
    {
        printf("{ name: %s,\n votes: %d,\n is_eliminated: %d\n}\n", candidates[i].name, candidates[i].votes, candidates[i].is_eliminated);
    } */

    // get the number of voters
    int number_of_voters = get_int("Voters: ");

    int preferences[number_of_voters][number_of_candidates];

    // now, every voters must vote
    // suppose there are 4 candidates, every voter should vote 4 times
    for (int i = 0; i < number_of_voters; i++)
    {
        printf("Voter %d\n", (i + 1));
        for (int j = 0; j < number_of_candidates; j++)
        {
            string preference = get_string("Rank %d: ", (j + 1));
            //printf("the preference expressed is: %s\n", preference);
            for (int k = 0; k < number_of_candidates; k++)
            {
                // error to check: what if the user inputs a name that is not in the candidates array?

                //printf("we are comparing: %s and %s\n", preference, candidates[k].name);
                if (strcmp(preference, candidates[k].name) == 0)
                {
                    preferences[i][j] = k;
                }
            }
        }
    }
    
    // here, every voter has expressed their preference
    // we should check if there is a winner, so we should check if there is a candidate that is put as the first preference more than 50% of the time
    for (int i = 0; i < number_of_voters; i++)
    {
        int first_rank = preferences[i][0];
        candidates[first_rank].votes++;
    }

    bool is_there_winner = false;
    int winner_index = -1;
    for (int i = 0; i < number_of_candidates; i++)
    {
        if (candidates[i].votes > (number_of_voters / 2))
        {
            is_there_winner = true;
            winner_index = i;
        }
    }

    if (is_there_winner)
    {
        printf("there is a winner: %s\n", candidates[i].name);
    }
    else 
    {

    }


    // loop for printing the preferences array
    /* for (int i = 0; i < number_of_voters; i++)
    {
        printf("Preferences of voter %d -> ", i);
        for (int j = 0; j < number_of_candidates; j++)
        {
            printf("%d ", preferences[i][j]);
        }
        printf("\n");
    } */
}