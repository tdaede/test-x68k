test.X: test Makefile human68kxfile.x
	./elf2x.py test

test: test.c Makefile human68kxfile.x
	m68k-linux-gnu-gcc -O2 -m68000 -nostdlib -fomit-frame-pointer -c test.c --specs=/usr/lib/gcc/m68k-linux-gnu/16/picolibc.specs
	m68k-linux-gnu-gcc -Wl,-static -o test -T ./human68kxfile.x test.o --specs=/usr/lib/gcc/m68k-linux-gnu/16/picolibc.specs -Wl,-q -Wl,--entry=_start -L./

clean:
	rm -f test test.X

.PHONY: clean
