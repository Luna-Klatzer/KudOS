/*
 * kernel.c
 *
 * Created: 12.03.2021
 * Author: Nicolas
 * Description: Core Kernel file which contains the core calls
 */ 

#include "../cmd/core.h"
#include "core/types.h"
#include "core/startup.h"
#include "core/interface/extra_print.h"
#include "core/interface/print.h"
#include "core/convert.h"
#include "core/cpuid.h"
#include <stdbool.h>

// The global ERROR_MSG variable will be updated whenever a exception was raised
char *ERROR_MSG = "";

/// Startup Function used for starting the OS processes
/// Currently only used for printing! 
uint8_t construct() {
    clear_console();
    print_start_symbol();

    return SUCCESS;
}

/// Main Method that starts the Core Kernel
void kernel_main() {
    // Constructing the base of the operating system
    uint8_t success = construct();
    if (success == SUCCESS)
    {
        // Enabling the command line after constructing the base of the operating system 
        cmd();

        get_vendor_id(); // Trying to fetch the vendor id
        return;
    }

    print("FAILED TO START! ERROR:");
    print(ERROR_MSG);
}

