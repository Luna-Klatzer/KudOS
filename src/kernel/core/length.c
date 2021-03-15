/*
 * length.c
 *
 * Created: 13.03.2021
 * Author: Nicolas-Klatzer
 * Description: Fetches lenght of strings and ints
 */ 
#include <stddef.h>
#include <stdbool.h>

/* Returns the length (amount digits)  of the passed integer */
int get_int_len(int num)
{
  int len = 0;
  int num_to_use = num;
  while (num_to_use != 0)
  {
    len++;
    num_to_use -= num_to_use % 10;
    num_to_use /= 10;
  }
  return len;
}

/* 
 * Returns the length of the passed string based on checking the content
 * with NULL or @\0 which end a string 
 */
int get_str_len(char *string)
{
  int len = 0;
  for (int i = 0; ; i++)
  {
    if (string[i] == '\0') return len;
    len++;
  }
}

/* Returns the length (amount digits) of the passed long */
int get_long_len(long value)
{
  int len = 0;
  long v = value;
  while (v != 0)
  {
    len++;
    v -= v % 10;
    v /= 10;
  }
  return len;
}

/* Returns the length (amount digits) of the passed long long */
int get_long_long_len(long long value)
{
  int len = 0;
  long long v = value;
  while (v != 0)
  {
    len++;
    v -= v % 10;
    v /= 10;
  }
  return len;
}

/* Returns the length of the passed hex string */
int get_hex_len(char *hex)
{
  return get_str_len(hex);
}

/* Returns the length of the string that would be created based on the passed base and integer */
int get_int_base_len(unsigned long num, int base)
{
  int len = 0;
  unsigned long check_num = num;
  int check_num_len = get_long_len((long) check_num);

  for (int index = check_num_len - 1; check_num > 0 && index >= 0; index--, len++)
  {
    check_num -= (check_num % base);
    check_num /= base;
  }
  return len;
}