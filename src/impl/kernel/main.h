#pragma once

#include "../x86_64/intf/print.h"
#include "../x86_64/intf/startup.h"
#include "../x86_64/lib/base.h"
#include <stdbool.h>

#ifndef MAIN_H_
#define MAIN_H_

uint8_t startup();
void kernel_main();

#endif