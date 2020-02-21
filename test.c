// based on musl libc syscall
static inline long __iocscall_a1(unsigned char n, long a)
{
	register unsigned long d0 __asm__("d0") = n;
	register unsigned long a1 __asm__("a1") = a;
	__asm__ __volatile__ ("trap #15" : "+r"(d0)
                        : "r"(a1)
                        : "memory");
	return d0;
}

static inline void __exit()
{
	__asm__ __volatile__ (".short 0xff00" :
                        :
                        : "memory");
}

const char *s = "Hello, world!\r\n";

void _start() {
  __iocscall_a1(0x21, (long)s);
  __exit();
}
