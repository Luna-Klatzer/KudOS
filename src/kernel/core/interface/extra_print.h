/*
 * extra_print.h
 *
 * Created: 26.02.2021
 * Author: Nicolas
 * Description: Additional functions used for printing content directly to the raw Console
 */ 

#pragma once

#include "../types.h"
#include "print.h"
#include <stdint.h>
#include <stddef.h>

#ifndef EXTRA_PRINT_H_
#define EXTRA_PRINT_H_

#if __cplusplus
extern "C" {
#endif


void print_chars(char character, uint8_t amount);
void print_new_lines(uint8_t amount);
void print_spaces(uint8_t amount);
void printnl(char* str);

#if __cplusplus
}
#endif

#endif