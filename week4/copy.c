#include "cs50.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = malloc(strlen(s) + 1);

    for (int i = 0; i < strlen(s) + 1; i++)
    {
        t[i] = s[i];
    }

}