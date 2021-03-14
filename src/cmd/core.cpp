/*
 * main.cpp
 *
 * Created: 12.03.2021
 * Author: Nicolas
 * Description: Main file for the Command Line that has direct interaction access to the kernel
 */ 

#include "../kernel/core/interface/print.h"

class KernelCMD
{
  public:
    /// Simulates a simple sleep()
    void delay_cmd()
    {
      for (long i = 0; i < 294967294; i++)
      {
        continue;
      }
      return;
    }

    /// Starts the global command line for user interaction
    void cmd()
    {
      delay_cmd();
      clear_console();
      print_line("Not implemented yet!");
    }
};

KernelCMD console_interface = KernelCMD();

#define _SepArg_ , // Comma macro

///
/// Indirection for the core Kernel Method which is in C++ and contains C++ name mangling 
///
#define _Generate_Indirection_RetEArgs(ret, name, ThisType, thisArg) \
extern "C" ret name ( ThisType thisArg ) \
{                   \
  return thisArg.name();      \
}                   \

_Generate_Indirection_RetEArgs(void, cmd, KernelCMD, console_interface);
