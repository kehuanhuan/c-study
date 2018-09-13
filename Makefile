CC=gcc

all: edit

edit : main.o hello.o
	$(CC) -o edit main.o hello.o
main.o : main.c static_lib.h
	$(CC) -c main.c
hello.o : src/hello.c
	$(CC) -c src/hello.c

clean-all :
	rm main.o hello.o edit

clean :
	rm main.o hello.o

.PHONY: edit clean

