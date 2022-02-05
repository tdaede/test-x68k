test.X: test Makefile
	./elf2x.py test

test: test.c Makefile
	m68k-linux-gnu-gcc -O2 -m68000 -nostdlib -fomit-frame-pointer -c test.c
	m68k-linux-gnu-ld -static -o test -q -T ./human68kxfile.x test.o

clean:
	rm -f test test.X

.PHONY: clean
