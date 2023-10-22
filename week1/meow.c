#include <stdio.h>
#include "cs50.h"

int main(void)
{
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}