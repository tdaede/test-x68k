test: test.c Makefile
	m68k-linux-gnu-gcc -O2 -m68000 -nostdlib -fomit-frame-pointer -c test.c -I/opt/toolchains/human68k/human68k/include
	m68k-linux-gnu-ld -static -o test -q -T ./human68kxfile.x -L/opt/toolchains/human68k/human68k/lib/ test.o -liocs

TEST.X: test Makefile
	human68k-objcopy -v -O xfile test TEST.X
