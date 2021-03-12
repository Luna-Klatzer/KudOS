/*
 * types.h
 *
 * Created: 12.03.2021
 * Author: Nicolas
 * Description: Type Declaration Header file used to declare types with pre-set global bit-sizes to avoid compiling issues
 */ 
#pragma once

#include <stdbool.h>
#include <stddef.h>

#ifndef TYPES_H
#define TYPES_H

#if __cplusplus
extern "C" {
#endif

    enum {
        SUCCESS = 0,
        FAILURE = 1,
        CRITICAL = 2,
    };

#if __cplusplus
}
#endif

#endif