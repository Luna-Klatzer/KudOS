/*
 * extra_print.h
 *
 * Created: 26.02.2021
 * Author: Nicolas
 * Description: Additional functions used for printing content directly to the raw Console
 */ 

#include "print.h"

#ifndef EXTRA_PRINT_H_
#define EXTRA_PRINT_H_

void print_chars(char character, uint8_t amount);
void print_new_lines(uint8_t amount);
void print_spaces(uint8_t amount);

#endif