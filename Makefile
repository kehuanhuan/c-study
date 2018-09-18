CC=gcc
bin=bin
rpath=/var/code/c-study/

all: edit

edit : main.o add.o sub.o libtest.so
	$(CC) -o $(bin)/edit add.o sub.o main.o -L. -ltest -Wl,-rpath=$(rpath)
libtest.so : src/div.c src/mul.c
	$(CC) src/div.c src/mul.c -fPIC -shared -o libtest.so
main.o : main.c
	$(CC) -c main.c
add.o : src/add.c
	$(CC) -c src/add.c
sub.o : src/sub.c
	$(CC) -c src/sub.c

clean-all :
	rm *.o *.so $(bin)/edit

clean :
	rm *.o *.so

.PHONY: edit clean

