ENTRY(start)

SECTIONS
{
  . = 0x0100000;

  .boot :
  {
    KEEP(*(.multiboot_header))
  }

  .text :
  {
    *(.text)
    *(.multiboot)
  }

  .bss  :
  {
    *(.bss)
  }
}
