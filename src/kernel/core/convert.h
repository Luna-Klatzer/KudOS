/*
 * convert.h
 *
 * Created: 13.03.2021
 * Author: Nicolas
 * Description: Simple convert functions for datatypes
 */ 

#pragma once

#ifndef CONVERT_H_
#define CONVERT_H_

#if __cplusplus
extern "C" {
#endif

void int_to_string(char*, int);
int string_to_int(char*);
long hex_to_int(char*);

#if __cplusplus
}
#endif

#endif