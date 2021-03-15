/*
 * types.c
 *
 * Created: 14.03.2021
 * Author: Nicolas-Klatzer
 * Description: Utility functions for datatypes (int, char, long)
 */ 
#include "types.h"
#include "length.h"
#include "interface/print.h"

/*
 * Removes inside a string all control chars and overwrites the passed string
 * Max. length 2048
 */
void remove_control_chars(char* string, char* out)
{
  int string_index = 0;
  int i;
  int len = get_str_len(string);
  for (i = 0; i < len; i++, string_index++)
  {
    if (string[i] == '\0') return;
    else if (string[i] < 127 && string[i] > 31)
    {
      out[string_index] = string[i];
    }
    /* Avoiding every character that is not standard ASCII */
    else string_index--;
  }

  out[i] = '\0';
}

/*
 * Fills the passed string based on the passed integer
 * @param str The string that should be filled
 * @param num The integer that should be used for the conversion
 */
void int_to_string(int num, char *str)
{
  int rem;
  int len = get_int_len(num);
  int num_to_use = num;
  for (int i = 0; i < len; i++)
  {
    rem = num_to_use % 10;
    num_to_use = num_to_use / 10;
    str[len - (i + 1)] = (char) (rem + '0');
  }
  str[len] = '\0';
}
 
/*
 * Converts an int to an string
 * @param str The string that should be converted
 */
int string_to_int(char *str)
{
  int len = get_str_len(str);
  int num = 0;
  int multiplier = 1;
  int num_at_index;
 
  for (int i = 0; i < len; i++)
  {
    /* Finding out the reversed index of the num (right to left) */
    num_at_index = str[len - (i + 1)] - '0'; 

    /* Re-evaluating the multiplier since pow is not available */
    for (int x = 0; x < i; x++) multiplier *= 10; 
    num += num_at_index * multiplier;
    
    /* Resetting the multiplier to 1 */
    multiplier = 1;
  }
 
  return num;
}

/*
 * Converts an hex number to an int
 * If an invalid character is inside the string it will return -1 (Control chars will be automatically removed)
 * Max. Hex length is 32 Bit / 4 Byte / 8 Hex
 * @param str The string that should be converted
 */
int hex_to_int(char *str)
{
  char buf[9] = "\0";
  remove_control_chars(str, buf);
  int str_len = get_str_len(buf);
  int sum = 0;
  int multiplier = 1;

  /* Calculating the multiplier for the biggest number (num at index 0) */ 
  for (int i = 1; i < str_len; i++) multiplier *= 16;

  /* Adding the multiplied value to the sum and then diving by the base (16) */
  for (int i = 0; i < str_len; i++, multiplier /= 16)
  {
    char byte = buf[i];
    if (byte >= '0' && byte <= '9') sum += (byte - '0') * multiplier;
    else if (byte >= 'A' && byte <='F') sum += (byte - 'A' + 10) * multiplier;
    else if (byte >= 'a' && byte <='f') sum += (byte - 'a' + 10) * multiplier;
    else return -1;
  }
  return sum;
}

/*
 * Converts an hex number to an long integer
 * If an invalid character is inside the string it will return -1
 * Max. Hex length is 64 Bit / 8 Byte / 16 Hex
 * @param str The string that should be converted
 */
long hex_to_long(char *str)
{
  char buf[17] = "\0";
  remove_control_chars(str, buf);
  int str_len = get_str_len(buf);
  long sum = 0;
  long multiplier = 1;
  /* Calculating the highest multiplier */
  for (int i = 1; i < str_len; i++) multiplier *= 16;

  /* Adding the multiplied value to the sum and then diving by the base (16) */
  for (int i = 0; i < str_len; i++, multiplier /= 16)
  {
    char byte = buf[i];
    if (byte >= '0' && byte <= '9') sum += (byte - '0') * multiplier;
    else if (byte >= 'A' && byte <='F') sum += (byte - 'A' + 10) * multiplier;
    else if (byte >= 'a' && byte <='f') sum += (byte - 'a' + 10) * multiplier;
    else return -1;
  }
  return sum;
}

bool valid_hex_char(char byte)
{
  return (byte >= '0' && byte <= '9') || (byte >= 'A' && byte <= 'F') || (byte >= 'a' && byte <= 'f');
}

bool valid_hex(char *hex)
{
  int str_len = get_str_len(hex);
  char byte;
  for (int i = 0; i < str_len; i++)
  {
    byte = hex[i];
    if (!valid_hex_char(byte)) return false;
  }
  return true;
}

/*
 * Converts an hex number to an dual ascii character and returns it
 * @param hex The string that should be converted
 */
char dual_hex_to_ascii(char *hex)
{
  return (char) hex_to_int(hex);
}

/*
 * Converts an hex number to an ascii string
 * @param hex The string that should be converted
 * @param output The initialised string which will be overwritten
 */
void hex_to_ascii(char *hex, char *output)
{
  char storage[3] = "  \0";
  int i = 0;
  int len = get_hex_len(hex);
  for (int hex_index = 0; hex_index < len; hex_index += 2)
  {
    if (valid_hex_char(hex[hex_index]))
    {
      storage[0] = hex[hex_index];
      if (valid_hex_char(hex[hex_index+1]))
      {
        storage[1] = hex[hex_index+1];
      }
      else
      {
        storage[1] = '\0';
      }

      output[i] = dual_hex_to_ascii(storage);
      i++;
    }
    else
    {
      break;
    }
  }
  output[i] = '\0';
}

/*
 * Flips the passed string and returns it with the indexes flipped (first index => last index)
 * @param string String that will be reversed
 * @param out String Array that will be written to
 */
void reverse_str(char* string, char* out)
{
  int str_len = get_str_len(string);
  out[str_len] = '\0';
  for (int i = str_len - 1; i >= 0; i--)
  {
    out[i] = string[str_len - 1 - i];
  }
}


/*
 * Copies a string to another string
 * @param string String to copy
 * @param out Output String where the string should be copied to
 * @param index The starting index of out where the string should be copied to
 */
void str_copy(char* string, char* out, int index)
{
  int str_len = get_str_len(string);
  for (int i = 0; i < str_len; i++, index++)
  {
    out[index] = string[i];
  }
}

/* Currently not used but will later be implemented with macros */
typedef struct {
  char* string;
  char* out;
  int index;
} str_copy_args;

void str_copy_wrapper(str_copy_args in)
{
  char* string = in.string;
  char* out = in.out;
  int index = in.index ? in.index : 0;
  str_copy(string, out, index);
}

