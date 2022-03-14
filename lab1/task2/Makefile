main:
	gcc -Wall -c task2.c
	gcc -Wall task2.o main.c -o main
clean:
	rm -f *.o main
	rm -f *.so main
	rm -f *.a main

create_static:
	gcc -Wall -c task2.c
	ar rcs libtask2.a task2.o

compile_static:
	make create_static
	gcc -Wall -c main.c
	gcc -Wall main.o libtask2.a -o static

create_shared:
	gcc -Wall -fPIC -c task2.c
	gcc -Wall -shared task2.o -o libtask2.so

compile_shared:
	make create_shared
	gcc -Wall -c main.c
	gcc -Wall main.o -L. -ltask2 -Wl,-rpath=. -o shared





