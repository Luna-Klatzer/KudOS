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
/// @param str The string that should be filled
/// @param num The integer that should be used for the conversion
void int_to_string(int num, char *str)
{
    int rem;
 
    int len = get_int_len(num);
    for (int i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}
 
/// Converts an int to an string
/// @param str The string that should be converted
int string_to_int(char *str)
{
    int len = get_str_len(str);
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

long hex_to_int(char *str)
{
    int strlen = get_str_len(str);
    long sum = 0;
    long long multiplier = 1;
    // Calculating the highest multiplier
    for (int i = 1; i < strlen; i++) multiplier *= 16;
    
    // Adding the multiplied value to the sum and then diving by the base (16)
    for (int i = 0; i < strlen; i++, multiplier /= 16)
    {
        char byte = str[i];
        if (byte >= '0' && byte <= '9') sum += (byte - '0') * multiplier;
        else if (byte >= 'A' && byte <='F') sum += (byte - 'A' + 10) * multiplier;
        else if (byte >= 'a' && byte <='f') sum += (byte - 'a' + 10) * multiplier;  
        else return -1;
    }
    return sum;
}
