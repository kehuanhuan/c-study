CC=gcc
bin=bin
rpath=`pwd`

all: edit

edit : main.o functions.o
	$(CC) -o $(bin)/edit main.o functions.o
main.o : main.c
	$(CC) -c main.c
functions.o : src/tools/functions.c
	$(CC) -c src/tools/functions.c

clean-all :
	rm *.o $(bin)/edit

clean :
	rm *.o

.PHONY: edit clean

