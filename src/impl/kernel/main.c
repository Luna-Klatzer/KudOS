/*
 * main.c
 *
 * Created: 26.02.2021
 * Author: Nicolas
 * Description: Main Kernel File used to start the OS
 */ 

#include "main.h"

// The global ERROR_MSG variable will be updated whenever a exception was raised
char *ERROR_MSG = "";


// Startup Function used for starting the OS processes
// Currently only used for printing!
uint8_t startup() {
    clear_console();
    kudoos_symbol();

    return SUCCESS;
}


// Main Method that starts the Core Kernel
void kernel_main() {
    uint8_t success = startup();
    if (success == SUCCESS)
    {
        return;
    }
    else
    {
        print("FAILED TO START! ERRORCODE:");
        print(ERROR_MSG);
    }
}