#include <stdio.h>
#include "cs50.h"

float average(int array[]);

const int LEN = 3;

int main(void)
{
    int scores[LEN];
    for (int i = 0; i < LEN; i++)
    {
        scores[i] = get_int("Score: "); 
    }
    printf("Average: %f\n", average(scores));
}

float average(int array[])
{
    int sum = 0;
    for (int i = 0; i < LEN; i++)
    {
        sum += array[i];
    }
    return sum / (float) LEN;
}