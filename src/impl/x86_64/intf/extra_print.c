/*
 * extra_print.c
 *
 * Created: 26.02.2021
 * Author: Nicolas
 * Description: Additional functions used for printing content directly to the raw Console
 */ 

#include "extra_print.h"

void print_chars(char character, uint8_t amount) {
    for (uint8_t i = 0; i < amount; i++)
    {
        print_char(character);
    }
}

void print_new_lines(uint8_t amount) {
    for (uint8_t i = 0; i < amount; i++)
    {
        newline();
    }
}

void print_spaces(uint8_t amount) {
    for (uint8_t i = 0; i < amount; i++)
    {
        print_char(' ');
    }
}
