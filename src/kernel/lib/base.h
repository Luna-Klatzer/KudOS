/*
 * base.h
 *
 * Created: 26.02.2021
 * Author: Nicolas
 */ 

#include <stddef.h>

#ifndef BASE_H_
#define BASE_H_

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