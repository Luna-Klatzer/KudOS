/*
 * cpuid.h
 *
 * Created: 13.03.2021
 * Author: Nicolas-Klatzer
 * Description: File containing functions for fetching cpu info using assembly cpuid
 */ 
#pragma once

#ifndef CPUID_H_
#define CPUID_H_

#if __cplusplus
extern "C" {
#endif

void get_vendor_id(char* out);

#if __cplusplus
}
#endif

#endif
