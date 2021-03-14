/*
 * length.c
 *
 * Created: 13.03.2021
 * Author: Nicolas-Klatzer
 * Description: Fetches lenght of strings and ints
 */ 
#pragma once

#ifndef LENGTH_H_
#define LENGTH_H_

#if __cplusplus
extern "C" {
#endif

int get_int_len(int num);
int get_str_len(char *string);
int get_hex_len(char *hex);
int get_long_len(long value);
int get_long_long_len(long long value);
int get_int_base_len(unsigned long num, int base);

#if __cplusplus
}
#endif

#endif
