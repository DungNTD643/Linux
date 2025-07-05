all: 
	gcc -o strutils.o -c strutils.c
	ar rcs libstrutils.a strutils.o
	gcc main.c -L. -lstrutils -o main_static


	gcc -c -fPIC strutils.c -o strutils.o
	gcc -shared -o libstrutils.so strutils.o
	gcc main.c -L. -lstrutils -o main_shared
	LD_LIBRARY_PATH=.
static:
	gcc -o strutils.o -c strutils.c
	ar rcs libstrutils.a strutils.o
	gcc main.c -L. -lstrutils -o main_static

shared:
	gcc -c -fPIC strutils.c -o strutils.o
	gcc -shared -o libstrutils.so strutils.o
	gcc main.c -L. -lstrutils -o main_shared
	LD_LIBRARY_PATH=.

clean:
	rm -f *.o *.a *.so main_static main_shared

