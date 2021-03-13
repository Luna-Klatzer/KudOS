/*
 * cpuid.h
 *
 * Created: 13.03.2021
 * Author: Nicolas
 * Description: File containing functions for fetching cpu info using assembly cpuid
 */ 
#pragma once

#ifndef CPUID_H_
#define CPUID_H_

#if __cplusplus
extern "C" {
#endif

char* get_vendor_id();

#if __cplusplus
}
#endif

#endif
