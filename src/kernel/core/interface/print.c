/*
 * print.c
 *
 * Created: 26.02.2021
 * Author: Nicolas-Klatzer
 * Description: Print Utility to interact with the Console Interface 
 */

#include <stdint.h>
#include <stddef.h>
#include "print.h"
#include "../length.h"

/// Char struct used to represent a Character
/// @param character character of the Char struct
/// @param color color that should be used for the Char
struct Char {
  uint8_t character;
  uint8_t color;
};


// Graphical buffer at 0xb8000 which can be accessed using the index
struct Char* buffer = (struct Char*) 0xb8000;
size_t column = 0; // storing the current column position
size_t row = 0; // storing the current row position

// Default color => WHITE | BLACK
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4; 


/// Clears a specified row by the passed index on the Console 
void clear_row(size_t row) {
  struct Char empty = (struct Char) {
    .character=' ',
    .color=color
  };

  // Overwriting all characters (column) in the current row
  for (size_t column = 0; column < NUM_COLS; column++)
  {
    // index of the character in the column
    buffer[column + NUM_COLS * row] = empty;
  }
}


/// Overwrites the content of the specified line.  
/// Will jump to the next line if the length is exceeding the max. columns
/// The cursor will "not" move and writing can continue on the last
/// written line
/// @param str String that will be used to overwrite the specified line
/// @param row Row that will be overwritten
void overwrite_row(char* str, size_t overwrite_row) {
  // Stores the row of the last print
  size_t pre_row = row;
  // Stores the column of the last print
  size_t pre_col = column;

  // Changing the current row and column so
  row = overwrite_row;
  column = 0;
  print(str);

  row = pre_row;
  column = pre_col;
}


/// Clears the entire console interface
void clear_screen() {
  for (size_t i = 0; i < NUM_ROWS; i++)
  {
    clear_row(i);
  }
  column = 0;
  row = 0;
}


/// Creates a new line on the console
void newline() {
  column = 0;

  if (row < NUM_ROWS)
  {
    row++;
    return;
  }

  // Moving all content up by one row so the lowest line can be cleared
  for (size_t row = 1; row < NUM_ROWS; row++)
  {
    for (size_t column = 0; column < NUM_COLS; column++)
    {
      // Moving all Character upwards to make room for the new line
      struct Char character = buffer[column + NUM_COLS * row];
      buffer[column + NUM_COLS * (row - 1)] = character;
    }
  }

  clear_row(NUM_ROWS);
}


/// Prints the passed Character on the current line. 
/// Will jump to the next line if the end of the current line was reached
/// @param character Character that will be printed
void print_char(char character) {
  if (character == '\n')
  {
    newline();
    return;
  }

  // Avoiding that the print exceeds the index
  if (column >= NUM_COLS)
  {
    newline();
  }

  // Overwriting the buffer with a new character with the assigned color
  buffer[column + NUM_COLS * row] = (struct Char) {
    .character=(uint8_t) character,
    .color=color
  };

  // Next default column is gonna be used instead of the current one
  column++;
}


/// Prints the passed string (char array) in the current line. 
/// Will jump to the next line if the end of the current line was reached
/// @param str String that will be printed
void print(char* str) {
  for (size_t i = 0; ; i++)
  {
    char character = (uint8_t) str[i];

    if (character == '\0')
    {
      return;
    }

    print_char(character);
  }
}


/// Sets the current Console Color that will be applied to every newly written character
/// @param foreground Foreground Color
/// @param background Background Color
void set_console_color(uint8_t foreground, uint8_t background) {
  color = foreground + (background << 4);
}

/// Prints a certain character on the console
/// @param amount Amount of the character
void print_chars(char character, uint8_t amount) {
  for (uint8_t i = 0; i < amount; i++)
  {
    print_char(character);
  }
}

/// Prints new lines on the console
/// @param amount Amount of the new lines
void print_new_lines(uint8_t amount) {
  print_chars('\n', amount);
}

/// Prints spaces in the current line
/// @param amount Amount of the spaces
void print_spaces(uint8_t amount) {
  print_chars(' ', amount);
}

/// Prints the entered string and jumps to the next line
/// @param str String that will be printed
void print_line(char* str) {
  print(str);
  newline();
}


/// Writes to the passed string outbuf the modified value based on the number base (10/16)
/// If the base is OVER 16 it will write -1 into the outbuf!
/// @param num The positive integer that should be modified
/// @param base The base for the number
/// @param outbuf Initialised char array that can hold the numbers. Watch the length!
void print_num(unsigned long n, int base, char *outbuf)
{
  if (base > 16)
  {
    outbuf[0] = '-';
    outbuf[1] = '1';
    outbuf[2] = '\0';
  }
  // Possible usable characters
  char *chars = "0123456789ABCDEF";

  unsigned long check_num = n;
  // Finding the length of the output hex number
  int len = get_int_base_len(check_num, 16);
  int index;

  // Overwriting the passed string with the hex chars
  for (index = len - 1; n > 0 && index >= 0; index--)
  {
    outbuf[index] = chars[n % base];
    n -= (n % base);
    n /= base;
  }

  // Avoiding that any random characters are getting returned after the hex string
  outbuf[len] = '\0';
}
