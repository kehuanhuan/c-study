edit : main.o hello.o
	gcc -o edit main.o hello.o
main.o : main.c static_lib.h
	gcc -c main.c
hello.o : src/hello.c
	gcc -c src/hello.c

clean :
	rm main.o hello.o

.PHONY: edit clean