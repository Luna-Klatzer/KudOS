/*
 * length.c
 *
 * Created: 13.03.2021
 * Author: Nicolas
 * Description: Fetches lenght of strings and ints
 */ 
#include <stddef.h>

/// Returns the length (digits) of the passed integer
int get_int_len(int value)
{
    int len = 0;
    int v = value;
    while (v != 0)
    {
        len++;
        v -= v % 10;
        v /= 10;
    }
    return len;
}

/// Returns the length of the passed string based on checking the content 
/// with NULL or @\0 which end a string
int get_str_len(char *string)
{
    int len = 0;
    for (int i = 0; 1; i++)
    {
        if (string[i] == '\0' || !string) return len;
        len++;
    }
}

/// Returns the length (digits) of the passed long
int get_long_len(long value)
{
    int len = 0;
    long v = value;
    while (v != 0)
    {
        len++;
        v -= v % 10;
        v /= 10;
    }
    return len;
}

/// Returns the length (digits) of the passed long long
int get_long_long_len(long long value)
{
    int len = 0;
    long long v = value;
    while (v != 0)
    {
        len++;
        v -= v % 10;
        v /= 10;
    }
    return len;
}