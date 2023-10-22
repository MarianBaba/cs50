#include <stdio.h>
#include <string.h>
#include "../cs50.h"

// function prototypes
string get_cc_number(void);
bool is_valid(string cc_number);

// implementation of Luhn's algorithm and recognizing credit card numbers
int main(void)
{
    string cc_number = get_cc_number();
    int length = strlen(cc_number);

    int sum = 0;
    int cc_first_digit = ((cc_number[0] - '0'));
    for (int i = length - 2; i >= 0; i = i - 2)
    {
        int current_num = ((cc_number[i] - '0')) * 2;
        if (current_num < 10)
        {
            sum = sum + current_num;
        }
        else
        {
            int first = current_num / 10;
            int second = current_num % 10;
            sum = sum + (first + second);
        }
    }
    for (int i = length - 1; i >= 0; i = i - 2)
    {
        int current_num = (cc_number[i] - '0');
        sum = sum + current_num;
    }
    if (sum % 10 == 0)
    {
        if (cc_first_digit == 3)
        {
            printf("AMEX\n");
        }
        else if (cc_first_digit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("MASTERCARD\n");    
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

string get_cc_number(void)
{
    string cc_number;
    do
    {
        cc_number = get_string("Number: ");
    } while (!is_valid(cc_number));
    return cc_number;
}

bool is_valid(string cc_number)
{   
    if (strlen(cc_number) == 0)
    {
        return false;
    }
    bool isValid = true;
    for (int i = 0; cc_number[i] != '\0'; i++) {
        if (cc_number[i] < '0' || cc_number[i] > '9') {
            isValid = false; // Non-digit character found
        }
    }
    return isValid;
}