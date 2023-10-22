#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        s[i] = toupper(s[i]);
        /* if (s[i] >= 'a' && s[i] < 'z')
        {
            s[i] -= 32;
        } */
    }
    printf("After: %s\n", s);
}