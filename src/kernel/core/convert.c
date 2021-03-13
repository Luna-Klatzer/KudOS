/*
 * convert.c
 *
 * Created: 13.03.2021
 * Author: Nicolas
 * Description: Simple convert functions for datatypes
 */ 
#include "convert.h"
#include "length.h"

/// Fills the passed string based on the passed integer
void int_to_string(char str[], int num)
{
    int rem;
 
    int len = intlen(num);
    for (int i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}
 
/// Converts an int to an string
int string_to_int(char str[])
{
    int len = strlen(str);
    int num = 0;
    int multiplier = 1;
    int num_at_index;
 
    for (int i = 0; i < len; i++)
    {
        num_at_index = str[len - (i + 1)] - '0';
        for (int x = 0; x < i; x++) multiplier *= 10;
        num += num_at_index * multiplier;
        multiplier = 1;
    }
 
    return num;
}