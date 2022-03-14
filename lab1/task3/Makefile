main:
	gcc -Wall -c task3.c
	gcc -Wall task3.o main.c -o main
	make clean
clean:
	rm -f *.o main

create_static:
	gcc -Wall -c task3.c
	ar rcs libtask3.a task3.o

compile_static:
	make create_static
	gcc -Wall -c main.c
	gcc -Wall main.o libtask3.a -o static

create_shared:
	gcc -Wall -fPIC -c task3.c
	gcc -Wall -shared task3.o -o libtask3.so

compile_shared:
	make create_shared
	gcc -Wall -c main.c
	gcc -Wall main.o -L. -ltask3 -Wl,-rpath=. -o shared

create_dynamic:
	gcc -Wall -fPIC -c task3.c
	gcc -Wall -shared task3.o -o libtask3.so

compile_dynamic:
	make create_dynamic
	gcc -Wall main2.c -o dynamic -ldl

tests_static:
	make create_static
	make compile_static
	printf "static:\n" > results3a.txt
	./static >> results3a.txt

tests_shared:
	make create_shared
	make compile_shared
	printf "shared:\n" >> results3a.txt
	./shared >> results3a.txt

tests_dynamic:
	make create_dynamic
	make compile_dynamic
	printf "dynamic:\n" >> results3a.txt
	./dynamic >> results3a.txt

tests_all:
	make tests_static
	make tests_shared
	make tests_dynamic

first_optimalization:
	make create_static
	make create_shared
	make create_dynamic
	make compile_static
	make compile_shared
	make compile_dynamic
	printf "O1 optimalizanion:\n" > results3b.txt
	printf "static:\n" >> results3b.txt
	gcc -Wall -O1 -c main.c
	gcc -Wall -O1 main.o libtask3.a -o static
	./static >> results3b.txt
	printf "shared:\n" >> results3b.txt
	gcc -Wall -O1 -c main.c
	gcc -Wall -O1 main.o -L. -ltask3 -Wl,-rpath=. -o shared
	./shared >> results3b.txt
	printf "dynamic:\n" >> results3b.txt
	gcc -Wall -O1 main2.c -o dynamic -ldl
	./dynamic >> results3b.txt

second_optimalization:
	make create_static
	make create_shared
	make create_dynamic
	make compile_static
	make compile_shared
	make compile_dynamic
	printf "O2 optimalizanion:\n" >> results3b.txt
	printf "static:\n" >> results3b.txt
	gcc -Wall -O2 -c main.c
	gcc -Wall -O2 main.o libtask3.a -o static
	./static >> results3b.txt
	printf "shared:\n" >> results3b.txt
	gcc -Wall -O2 -c main.c
	gcc -Wall -O2 main.o -L. -ltask3 -Wl,-rpath=. -o shared
	./shared >> results3b.txt
	printf "dynamic:\n" >> results3b.txt
	gcc -Wall -O2 main2.c -o dynamic -ldl
	./dynamic >> results3b.txt

third_optimalization:
	make create_static
	make create_shared
	make create_dynamic
	make compile_static
	make compile_shared
	make compile_dynamic
	printf "O3 optimalizanion:\n" >> results3b.txt
	printf "static:\n" >> results3b.txt
	gcc -Wall -O3 -c main.c
	gcc -Wall -O3 main.o libtask3.a -o static
	./static >> results3b.txt
	printf "shared:\n" >> results3b.txt
	gcc -Wall -O3 -c main.c
	gcc -Wall -O3 main.o -L. -ltask3 -Wl,-rpath=. -o shared
	./shared >> results3b.txt
	printf "dynamic:\n" >> results3b.txt
	gcc -Wall -O3 main2.c -o dynamic -ldl
	./dynamic >> results3b.txt

tests_with_optimalization:
	make first_optimalization
	make second_optimalization
	make third_optimalization









