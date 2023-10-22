#include <stdio.h> // proprocessor directive -> #INCLUDE is pre processed
#include "cs50.h"

int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s!\n", name);
}