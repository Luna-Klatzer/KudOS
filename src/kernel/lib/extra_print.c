/*
 * extra_print.c
 *
 * Created: 26.02.2021
 * Author: Nicolas
 * Description: Additional functions used for printing content directly to the raw Console
 */ 

#include "extra_print.h"

/// Prints a certain character on the console
/// 
///  @param amount Amount of the character
void print_chars(char character, uint8_t amount) {
    for (uint8_t i = 0; i < amount; i++)
    {
        print_char(character);
    }
}

/// Prints new lines on the console
/// 
///  @param amount Amount of the new lines
void print_new_lines(uint8_t amount) {
    print_chars('\n', amount);
}

/// Prints spaces in the current line
/// 
///  @param amount Amount of the spaces
void print_spaces(uint8_t amount) {
    print_chars(' ', amount);
}

/// Prints the entered string and jumps to the next line
/// 
///  @param str String that will be printed
void printnl(char* str) {
    print(str);
    newline();
}