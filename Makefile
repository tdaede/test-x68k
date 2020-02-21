test: test.c Makefile
	m68k-linux-gnu-gcc -O2 -m68000 -nostdlib -fomit-frame-pointer -c test.c
	m68k-linux-gnu-ld -q -T ./human68kxfile.x test.o -o test

TEST.X: test Makefile
	human68k-objcopy -v -O xfile test TEST.X
