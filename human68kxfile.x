/* Default linker script, for normal executables */
OUTPUT_FORMAT("elf32-m68k")
/* SEARCH_DIR("/home/thomas/.local/human68k/lib"); */
ENTRY (_start)
__data_size = 0;
stack_size = 8192;
SECTIONS
{
  /DISCARD/ : {
    *(.note.*)
    *(.comment)
  }
  .text : {
    KEEP (*(.text.init.enter))
   	KEEP (*(.data.init.enter))
    *(.init)
    *(.init.*)
     *(.header)
    . = ALIGN(4);
    *(.text)
    *(.text.*)
     *(.fini)
    . = ALIGN (4);
     etext = .;
     _etext = .;
  }
  .data : {
     __ctors_start = . ;
     *(.ctors)
     __ctors_end = . ;
     __dtors_start = . ;
     *(.dtors)
     __dtors_end = . ;
     __data_source = . ;
     __data_start = . ;
    KEEP(SORT(*)(.ctors))
    KEEP(SORT(*)(.dtors))
    *(.data)
    *(.data*)
    *(.rodata)  /* We need to include .rodata here if gcc is used */
    *(.rodata*) /* with -fdata-sections.  */
    *(.gcc_exc*)
    ___EH_FRAME_BEGIN__ = . ;
    *(.eh_fram*)
    ___EH_FRAME_END__ = . ;
    . = ALIGN (4);
     edata = .;
     _edata = .;
  }
  .bss :
  {
    __bss_start = .;
    *(.bss)
    *(COMMON)
    . = ALIGN (2);
     end = .;
     _end = .;
     __bss_size = . - __bss_start;
     __tls_base = .;
     . += stack_size;
     __stack = .;
  }
}
