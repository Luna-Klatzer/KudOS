#pragma once

#include "startup.h"
#include "lib/base.h"
#include "lib/extra_print.h"
#include "../x86_64/interface/print.h"
#include <stdbool.h>

#ifndef MAIN_H_
#define MAIN_H_

uint8_t startup();
void kernel_main();

#endif