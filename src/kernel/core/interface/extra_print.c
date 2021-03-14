/*
 * extra_print.c
 *
 * Created: 26.02.2021
 * Author: Nicolas
 * Description: Additional functions used for printing content directly to the raw Console
 */ 

#include "extra_print.h"
#include "../length.h"

/// Prints a certain character on the console
/// @param amount Amount of the character
void print_chars(char character, uint8_t amount) {
    for (uint8_t i = 0; i < amount; i++)
    {
        print_char(character);
    }
}

/// Prints new lines on the console
/// @param amount Amount of the new lines
void print_new_lines(uint8_t amount) {
    print_chars('\n', amount);
}

/// Prints spaces in the current line
/// @param amount Amount of the spaces
void print_spaces(uint8_t amount) {
    print_chars(' ', amount);
}

/// Prints the entered string and jumps to the next line
/// @param str String that will be printed
void printnl(char* str) {
    print(str);
    newline();
}


/// Writes to the passed string outbuf the modified value based on the number base (10/16)
/// @param num The positive integer that should be modified
/// @param base The base for the number
/// @param outbuf Initialised char array that can hold the numbers
void print_num(unsigned long n, int base, char *outbuf)
{
    char *chars = "0123456789ABCDEF";

    unsigned long check_num = n;
    int len = 0;
    int index;
    // Finding the length of the output hex number
    for (index = get_long_len((long) n) - 1; check_num > 0 && index >= 0; index--, len++)
    {
        check_num -= (check_num % base);
        check_num /= base;
    }

    // Overwriting the passed string with the hex chars
    for (index = len - 1; n > 0 && index >= 0; index--)
    {
        outbuf[index] = chars[n % base];
        n -= (n % base);
        n /= base;
    }

    // Avoiding that any random characters are getting returned after the hex string 
    outbuf[len] = '\0'; 
}