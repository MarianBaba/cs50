#include <stdio.h>
#include <string.h>
#include "cs50.h"

void print_bulbs(int num);

int main(void)
{
    string text = get_string("Message: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        print_bulbs(text[i]);
    }
}

void print_bulbs(int num)
{
    int binary_array[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int i = 0;
    while (num > 0)
    {
        int remainder = num % 2;
        binary_array[i] = remainder;
        num = num / 2;
        i++;
    }

    for (int i = 7; i >= 0; i--)
    {
        if (binary_array[i] == 0)
        {
            printf("⚫");
        }
        else 
        {
            printf("🟡");
        }
    }
    printf("\n");
}