test: test.c Makefile
	m68k-linux-gnu-gcc -O2 -m68000 -nostdlib -fomit-frame-pointer test.c -o test
	m68k-linux-gnu-strip -R .note.gnu.build-id -R .comment test

test.x: test Makefile
	human68k-objcopy -v -O xfile test test.x
