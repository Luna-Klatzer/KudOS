global long_mode_start
extern kernel_main

section .text
bits 64
long_mode_start:
    ; load null into all data segment registers
    mov ax, 0
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; print `STATUSOK` to screen
    mov dword [0xb8000], 0x2f542f53
    mov dword [0xb8004], 0x2f542f41
    mov dword [0xb8008], 0x2f532f55
    mov dword [0xb800c], 0x20202020
    mov dword [0xb8010], 0x2f4b2f4f

    call kernel_main
    hlt