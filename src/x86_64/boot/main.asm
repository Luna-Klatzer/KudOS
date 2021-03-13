global start
extern long_mode_start

section .text
bits 32
start:
	mov esp, stack_top

	call check_multiboot
	call check_cpuid
	call check_long_mode

	call setup_page_tables
	call enable_paging

	; passing the pointer for the global descripter table required for 64-Bit mode
	lgdt [gdt64.pointer] 
	; jumping to 64-Bit mode for running the subroutine long_mode_start which then calls the Kernel code
	jmp gdt64.code_segment:long_mode_start 

	hlt

check_multiboot:
	cmp eax, 0x36d76289
	jne .no_multiboot ; if not equal it will jump to the error field
	ret
.no_multiboot:
	mov al, "M"
	jmp error

; To check wether cpuid is available it will be attempted to flip one bit in the registry and see if it worked
; if in the end nothing has changed cpuid is not available and an error message will be visible on the screen
check_cpuid:
	pushfd
	pop eax
	mov ecx, eax ; making a copy of eax to check later if the registry changed
	xor eax, 1 << 21
	push eax
	popfd
	pushfd
	pop eax
	push ecx
	popfd
	cmp eax, ecx
	je .no_cpuid ; if equal it will jump to the error field
	ret
.no_cpuid:
	mov al, "C"
	jmp error

check_long_mode:
	; checking whether extended processor info is available by checking the size of the eax registry
    ; if the eax registry is not bigger than the passed value extended processor info is not available
	mov eax, 0x80000000
	cpuid
	cmp eax, 0x80000001 
	jb .no_long_mode

	; checking wether long_mode is available by using the cpuid instruction and hoping that the 29th (LM) bit is set
	; if after calling cpuid the 29th bit of the edx registry is not set that means that long_mode is not available
	mov eax, 0x80000001
	cpuid
	test edx, 1 << 29
	jz .no_long_mode
	
	ret
.no_long_mode:
	mov al, "L"
	jmp error

setup_page_tables:
	; enabling the tables and making their entries point to the lower one (l4 -> l3 -> l2)
	; the size is 4KB which means that the first 12 bits are used for flags
	mov eax, page_table_l3
	or eax, 0b11 ; enabling the flags: present, writable
	mov [page_table_l4], eax ; moving the modified table l3 with the set flags into the l4 table
	
	mov eax, page_table_l2
	or eax, 0b11 ; enabling the flags: present, writable
	mov [page_table_l3], eax ; moving the modified table l2 with the set flags into the l3 table

	mov ecx, 0 ; counter
; mapping in a for loop the entire l2 page 
; used for ease insted of an additional l1 table
.loop:

	mov eax, 0x200000 ; Allocating with the huge page flag 2MB
	mul ecx
	or eax, 0b10000011 ; enabling the flags: present, writable, huge page
	mov [page_table_l2 + ecx * 8], eax ; moving the new allocated 2MB into the l2 table

	inc ecx ; increment counter
	cmp ecx, 512 ; checks if the whole table is mapped
	jne .loop ; if not, continue

	ret

enable_paging:
	; pass page table location to cpu
	mov eax, page_table_l4
	mov cr3, eax ; the cpu will look in the cr3 registry for the pages

	; enable Physical Address Extension required for 64-Bit paging
	mov eax, cr4
	or eax, 1 << 5
	mov cr4, eax

	; enable long mode
	mov ecx, 0xC0000080
	rdmsr
	or eax, 1 << 8 ; enabling the long_mode bit flag
	wrmsr

	; enable paging
	mov eax, cr0
	or eax, 1 << 31 ; enabling the paging bit flag
	mov cr0, eax

	ret

error:
	; print "ERR: X" where X is the error code
	mov dword [0xb8000], 0x4f524f45
	mov dword [0xb8004], 0x4f3a4f52
	mov dword [0xb8008], 0x4f204f20
	mov byte  [0xb800a], al
	hlt

; Settings up paging where virtual addresses are mapped to actual addresses in the memory 
; every page has a size of 4KB and each entry points to the next lower page
; l1 is not used since the huge page flag is enabled which then allocates 2 MB that points directly to physical memory
section .bss
align 4096
page_table_l4:
	resb 4096
page_table_l3:
	resb 4096
page_table_l2:
	resb 4096
stack_bottom:
	resb 4096 * 4
stack_top:

section .rodata
gdt64: ; global descripter table required for 64-Bit
	dq 0 ; zero entry
.code_segment: equ $ - gdt64
	; bit 43 = executable flag
	; bit 44 = descripter type (code and data segment)
	; bit 47 = present flag
	; bit 53 = 64-Bit flag
	dq (1 << 43) | (1 << 44) | (1 << 47) | (1 << 53) ; code segment
.pointer:
	dw $ - gdt64 - 1 ; length
	dq gdt64 ; address