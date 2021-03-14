/*
 * types.h
 *
 * Created: 12.03.2021
 * Author: Nicolas
 * Description: Type Declaration Header file used to declare types with pre-set global bit-sizes to avoid compiling issues
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

#if __cplusplus
}
#endif

#endif