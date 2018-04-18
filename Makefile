CC=gcc

all: edit clean

edit : main.o hello.o
	$(CC) -o edit main.o hello.o
main.o : main.c static_lib.h
	$(CC) -c main.c
hello.o : src/hello.c
	$(CC) -c src/hello.c

clean :
	rm main.o hello.o

.PHONY: edit clean

