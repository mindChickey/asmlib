
libasmlib.a: _start0.o tools.o
	ar rcs libasmlib.a _start0.o tools.o

tools.o: tools.c
	clang -c tools.c -o tools.o -O

_start0.o: _start0.s
	clang -c _start0.s -o _start0.o -O

install: libasmlib.a
	cp libasmlib.a /usr/local/lib/
	mkdir -p /usr/local/include/asmlib
	cp asmlib.h /usr/local/include/asmlib
	cp exit0.h /usr/local/include/asmlib
	cp print_num.h /usr/local/include/asmlib
	cp print_stack.h /usr/local/include/asmlib
	cp write0.h /usr/local/include/asmlib

clean:
	rm -f libasmlib.a _start0.o tools.o