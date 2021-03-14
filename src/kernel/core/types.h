/*
 * types.h
 *
 * Created: 13.03.2021
 * Author: Nicolas-Klatzer
 * Description: Utility functions for datatypes (int, char, long)
 */
#pragma once

#include <stdbool.h>
#include <stddef.h>

#ifndef TYPES_H
#define TYPES_H

#if __cplusplus
extern "C" {
#endif

enum {
  SUCCESS = 0,
  FAILURE = 1,
  CRITICAL = 2,
};

void remove_control_chars(char* string, char* out);
bool valid_hex_char(char byte);
bool valid_hex(char *hex);
void int_to_string(int num, char *str);
int string_to_int(char *str);
int hex_to_int(char *str);
long hex_to_long(char *str);
char dual_hex_to_ascii(char *hex);
void hex_to_ascii(char *hex, char *output);
void reverse_str(char* string, char* out);
void str_copy(char* string, char* out, int index);

#if __cplusplus
}
#endif

#endif