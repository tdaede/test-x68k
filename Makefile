test: test.c Makefile
	m68k-linux-gnu-gcc -O2 -m68000 -nostdlib -fomit-frame-pointer -c test.c
	m68k-linux-gnu-ld -static -o test -q -T ./human68kxfile.x test.o

test.X: test Makefile
	./elf2x.py test

clean:
	rm -f test TEST.X

.PHONY: clean
