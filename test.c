// based on musl libc syscall
static inline long __syscall_a1(unsigned char n, long a)
{
	register unsigned long d0 __asm__("d0") = n;
	register unsigned long a1 __asm__("a1") = a;
	__asm__ __volatile__ ("trap #15" : "+r"(d0)
                        : "r"(a1)
                        : "memory");
	return d0;
}

char* s = "Hello, world!\n";

void _start() {
  __syscall_a1(0x21, (long)s);
}
