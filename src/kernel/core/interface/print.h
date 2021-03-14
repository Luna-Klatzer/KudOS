/*
 * print.h
 *
 * Created: 26.02.2021
 * Author: Nicolas-Klatzer
 * Description: Print Utility to interact with the Console Interface 
 */ 

#pragma once

#include "../types.h"
#include <stdint.h>
#include <stddef.h>

#ifndef PRINT_H_
#define PRINT_H_

#if __cplusplus
extern "C" {
#endif

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 20;

enum {
  PRINT_COLOR_BLACK = 0,
	PRINT_COLOR_BLUE = 1,
	PRINT_COLOR_GREEN = 2,
	PRINT_COLOR_CYAN = 3,
	PRINT_COLOR_RED = 4,
	PRINT_COLOR_MAGENTA = 5,
	PRINT_COLOR_BROWN = 6,
	PRINT_COLOR_LIGHT_GRAY = 7,
	PRINT_COLOR_DARK_GRAY = 8,
	PRINT_COLOR_LIGHT_BLUE = 9,
	PRINT_COLOR_LIGHT_GREEN = 10,
	PRINT_COLOR_LIGHT_CYAN = 11,
	PRINT_COLOR_LIGHT_RED = 12,
	PRINT_COLOR_PINK = 13,
	PRINT_COLOR_YELLOW = 14,
	PRINT_COLOR_WHITE = 15,
};

void clear_screen();
void newline();
void clear_row();
void overwrite_row(char* str, size_t overwrite_row);
void print_char(char character);
void print(char* string);
void set_console_color(uint8_t foreground, uint8_t background);
void print_chars(char character, uint8_t amount);
void print_new_lines(uint8_t amount);
void print_spaces(uint8_t amount);
void print_line(char* str);
void print_num(unsigned long n, int base, char *outbuf);

#if __cplusplus
}
#endif

#endif