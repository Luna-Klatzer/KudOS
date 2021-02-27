/*
 * print.c
 *
 * Created: 26.02.2021
 * Author: Nicolas
 * Description: Print Utility to interact with the Console Interface 
 */ 


#include "print.h"


// Char struct used to represent a Character
// ---
// character: character of the Char struct
// color: color that should be used for the Char
struct Char {
    uint8_t character;
    uint8_t color;
};


// Graphical buffer at 0xb8000 which can be accessed using the index
struct Char* buffer = (struct Char*) 0xb8000;
size_t col = 0; // storing the current colomn position
size_t row = 0; // storing the current row position

// Default color => WHITE | BLACK
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4; 


// Clears a specified row by the passed index on the Console 
void clear_row(size_t row) {
    struct Char empty = (struct Char) {
        .character=' ',
        .color=color
    };

    // Overwriting all characters (column) in the current row
    for (size_t col = 0; col < NUM_COLS; col++)
    {
        // index of the character in the colomn
        buffer[col + NUM_COLS * row] = empty;
    }
};


/** Overwrites the content of the specified line.  
 *  Will jump to the next line if the length is exceeding the max. colomns 
 *  The cursur will "not" move and writing can continue on the last 
 *  written line
 * 
 *  @param str String that will be used to overwrite the specified line
 *  @param row Row that will be overwritten
 */ 
void overwrite_row(char* str, size_t overwrite_row) {
    // Stores the row of the last print
    size_t pre_row = row;
    // Stores the col of the last print
    size_t pre_col = col;

    // Changing the current row and colomn so 
    row = overwrite_row;
    col = 0;
    print(str);

    row = pre_row;
    col = pre_col;
};


// Clears the entire console interface
void clear_console() {
    for (size_t i = 0; i < NUM_ROWS; i++)
    {
        clear_row(i);   
    }
}


// Creates a new line on the console
void newline() {
    col = 0;

    if (row < NUM_ROWS)
    {
        row++;
        return;
    }

    // Moving all content up by one row so the lowest line can be cleared
    for (size_t row = 1; row < NUM_ROWS; row++)
    {
        for (size_t col = 0; col < NUM_COLS; col++)
        {
            // Moving all Character upwards to make room for the new line
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clear_row(NUM_ROWS);
}


/** Prints the passed Character on the current line. 
 *  Will jump to the next line if the end of the current line was reached
 * 
 *  @param character Character that will be printed
 */ 
void print_char(char character) {
    if (character == '\n') 
    {
        newline();    
        return;
    }

    // Avoiding that the print exceeds the index
    if (col >= NUM_COLS)
    {
        newline();
    }

    // Overwriting the buffer with a new character with the assigned color 
    buffer[col + NUM_COLS * row] = (struct Char) {
        .character=(uint8_t) character,
        .color=color
    };
    
    // Next default colomn is gonna be used instead of the current one
    col++;
}


/** Prints the passed string (char array) in the current line. 
 *  Will jump to the next line if the end of the current line was reached
 * 
 *  @param str String that will be printed
 */ 
void print(char* str) {
    for (size_t i = 0; 1; i++)
    {
        char character = (uint8_t) str[i];

        if (character == '\0') 
        {
            return;
        }

        print_char(character);
    }
}


/** Sets the current Console Color that will be applied to every newly written character
 * 
 *  @param foreground Foreground Color
 *  @param background Background Color
 */ 
void set_console_color(uint8_t foreground, uint8_t background) {
    color = foreground + (background << 4);
}
