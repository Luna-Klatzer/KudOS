/*
 * main.hpp
 *
 * Created: 12.03.2021
 * Author: Nicolas-Klatzer
 * Description: Main file for the Command Line that has direct interaction access to the kernel
 */ 
#pragma once

#include "../kernel/core/types.h"

#ifndef CORE_HPP
#define CORE_HPP

#if __cplusplus
extern "C" {
#endif

void cmd();

#if __cplusplus
}
#endif


#endif
