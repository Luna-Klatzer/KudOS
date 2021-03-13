/*
 * cpuid.c
 *
 * Created: 13.03.2021
 * Author: Nicolas
 * Description: File containing functions for fetching cpu info using assembly cpuid
 */ 

#include <cpuid.h>
#include "cpuid.h"
#include "interface/print.h"
#include "convert.h"

/* Vendor-strings. */
#define CPUID_VENDOR_OLDAMD       "AMDisbetter!"
#define CPUID_VENDOR_AMD          "AuthenticAMD"
#define CPUID_VENDOR_INTEL        "GenuineIntel"
#define CPUID_VENDOR_OLDTRANSMETA "TransmetaCPU"
#define CPUID_VENDOR_TRANSMETA    "GenuineTMx86"
#define CPUID_VENDOR_CYRIX        "CyrixInstead"
#define CPUID_VENDOR_CENTAUR      "CentaurHauls"
#define CPUID_VENDOR_NEXGEN       "NexGenDriven"
#define CPUID_VENDOR_UMC          "UMC UMC UMC "
#define CPUID_VENDOR_SIS          "SiS SiS SiS "
#define CPUID_VENDOR_NSC          "Geode by NSC"
#define CPUID_VENDOR_RISE         "RiseRiseRise"
#define CPUID_VENDOR_VORTEX       "Vortex86 SoC"
#define CPUID_VENDOR_VIA          "VIA VIA VIA "
 
/*Vendor-strings from Virtual Machines.*/
#define CPUID_VENDOR_VMWARE       "VMwareVMware"
#define CPUID_VENDOR_XENHVM       "XenVMMXenVMM"
#define CPUID_VENDOR_MICROSOFT_HV "Microsoft Hv"
#define CPUID_VENDOR_PARALLELS    " lrpepyh vr"

/// Fetches the vendor id using assembly cpuid
char* get_vendor_id() 
{
    int asm_eax, asm_ebx, asm_ecx, asm_edx;

    __cpuid(0, asm_eax, asm_ebx, asm_ecx, asm_edx);

    char string[13]; 

    int_to_string(string, asm_eax);
    newline();
    print(string);
    int_to_string(string, asm_ebx);
    newline();
    print(string);
    int_to_string(string, asm_ecx);
    newline();
    print(string);
    int_to_string(string, asm_edx);
    newline();
    print(string);
    return "";
}