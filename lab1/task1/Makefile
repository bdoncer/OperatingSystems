main:
	gcc -Wall -c task1.c
	gcc -Wall task1.o main.c -o main
	make clean

clean:
	rm -f *.o main

create_static:
	gcc -Wall -c task1.c
	ar rcs libtask1.a task1.o

compile_static:
	make create_static
	gcc -Wall -c main.c
	gcc -Wall main.o libtask1.a -o static

create_shared:
	gcc -Wall -fPIC -c task1.c
	gcc -Wall -shared task1.o -o libtask1.so

compile_shared:
	make create_shared
	gcc -Wall -c main.c
	gcc -Wall main.o -L. -ltask1 -Wl,-rpath=. -o shared





