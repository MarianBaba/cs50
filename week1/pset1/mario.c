#include <stdio.h>
#include "../cs50.h"

int get_height(void);
void print_piramids(int height);

int main(void)
{
    int height = get_height();
    print_piramids(height);
}

int get_height(void) 
{
    int height;
    do {
        height = get_int("Height: ");
    }
    while (height < 1);
    return height;
}

void print_piramids(int height)
{
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (height - i - 1); j++)
        {   
            printf(" ");
        }
        for (int k = 0; k < height - (height - i - 1); k++) 
        {
            printf("#");
        }
        printf(" ");
        for (int j = 0; j < height - (height - i - 1); j++) 
        {
            printf("#");
        }
        printf("\n");
    }
}