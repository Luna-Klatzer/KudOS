/*
 * kernel.c
 *
 * Created: 12.03.2021
 * Author: Nicolas-Klatzer
 * Description: Core Kernel file which contains the core calls
 */ 

#include "../cmd/core.h"
#include "core/types.h"
#include "core/startup.h"
#include "core/interface/print.h"
#include "core/types.h"
#include <stdbool.h>

/* The global ERROR_MSG variable will be updated whenever a exception was raised */
char *ERROR_MSG = "";

/* 
 * Startup Function used for starting the OS processes
 * Currently only used for printing! 
 */
uint8_t construct() {
  clear_screen();
  print_start_symbol();

  return SUCCESS;
}

/* Main Method that starts the Core Kernel */
void kernel_main() {
  /* Constructing the base of the operating system */
  uint8_t success = construct();
  if (success == SUCCESS)
  {
    cmd();
    show_startup_hardware_info();

    return;
  }

  print("FAILED TO START! ERROR:");
  print(ERROR_MSG);
}

