/*
 * kernel.h
 *
 * Created: 12.03.2021
 * Author: Nicolas
 * Description: Core Kernel file which contains the core calls
 */ 

#include "kernel.h"

// The global ERROR_MSG variable will be updated whenever a exception was raised
char *ERROR_MSG = "";

class Kernel
{
    public:
        /// Startup Function used for starting the OS processes
        /// Currently only used for printing! 
        uint8_t construct() {
            clear_console();
            kudoos_symbol();

            // Some Testing stuff
            for (int i = 0; i < 16; i++)
            {
                print("x\n");
            }
            printnl("d");
            print("t");

            return SUCCESS;
        }

        /// Main Method that starts the Core Kernel
        void kernel_main() {
            uint8_t success = construct();
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
};

// Creating an instance of Kernel
Kernel kernel = Kernel();

#define _SepArg_ , // Comma macro

///
/// Indirection for the core Kernel Method which is in C++ and contains C++ name mangling 
///
#define _Generate_Indirection_RetEArgs(ret, name, ThisType, thisArg) \
extern "C" ret name ( ThisType thisArg ) \
{                                     \
    return thisArg.name();            \
}                                     \

_Generate_Indirection_RetEArgs(void, kernel_main, Kernel, kernel);
