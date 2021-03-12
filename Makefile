kernel_source_files := $(shell find src/kernel -name *.c)
kernel_object_files := $(patsubst src/kernel/%.c, build/kernel/%.o, $(kernel_source_files))

kernel_cpp_files := $(shell find src/kernel -name *.cpp)
kernel_cpp_object_files := $(patsubst src/kernel/%.cpp, build/kernel/%.o, $(kernel_cpp_files))

x86_64_c_source_files := $(shell find src/x86_64 -name *.c)
x86_64_c_object_files := $(patsubst src/x86_64/%.c, build/x86_64/%.o, $(x86_64_c_source_files))

x86_64_asm_source_files := $(shell find src/x86_64 -name *.asm)
x86_64_asm_object_files := $(patsubst src/x86_64/%.asm, build/x86_64/%.o, $(x86_64_asm_source_files))

x86_64_object_files := $(x86_64_c_object_files) $(x86_64_asm_object_files)

$(info $$kernel_source_files is [${kernel_source_files}])
$(info $$kernel_cpp_files is [${kernel_cpp_files}])
$(info $$x86_64_c_source_files is [${x86_64_c_source_files}])
$(info $$x86_64_asm_source_files is [${x86_64_asm_source_files}])

$(info $$kernel_object_files is [${kernel_object_files}])
$(info $$kernel_cpp_object_files is [${kernel_cpp_object_files}])
$(info $$x86_64_c_object_files is [${x86_64_c_object_files}])
$(info $$x86_64_asm_object_files is [${x86_64_asm_object_files}])
$(info $$x86_64_object_files is [${x86_64_object_files}])

$(kernel_object_files):
	mkdir -p $(dir $@) && \
	x86_64-elf-gcc -c -I src/x86_64 -ffreestanding $(patsubst build/kernel/%.o, src/kernel/%.c, $@) -o $@

$(kernel_cpp_object_files): 
	mkdir -p $(dir $@) && \
	x86_64-elf-gcc -c -I src/x86_64 -ffreestanding $(patsubst build/kernel/%.o, src/kernel/%.cpp, $@) -o $@
 
$(x86_64_c_object_files):
	mkdir -p $(dir $@) && \
	x86_64-elf-gcc -c -I src/x86_64 -ffreestanding $(patsubst build/x86_64/%.o, src/x86_64/%.c, $@) -o $@

$(x86_64_asm_object_files):
	mkdir -p $(dir $@) && \
	nasm -f elf64 $(patsubst build/x86_64/%.o, src/x86_64/%.asm, $@) -o $@

.PHONY: build-x86_64
build-x86_64: $(kernel_object_files) $(kernel_cpp_object_files) $(x86_64_object_files)
	mkdir -p dist/x86_64 && \
	x86_64-elf-ld -n -o dist/x86_64/kernel.bin -T targets/x86_64/linker.ld $(kernel_object_files) $(kernel_cpp_object_files) $(x86_64_object_files) && \
	cp dist/x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin && \
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86_64/kernel.iso targets/x86_64/iso
