CC=gcc
bin=bin
lib=lib
rpath=`pwd`

all: hello

hello : main.c libkhhfuns.so
	$(CC) main.c -L./lib/ -lkhhfuns -o $(bin)/hello
libkhhfuns.so : src/tools/functions.c
	$(CC) -fPIC -shared src/tools/functions.c -o $(lib)/libkhhfuns.so

clean :
	rm -rf *.o $(bin) $(lib) /usr/lib/libkhhfuns.so

install :
	cp $(lib)/libkhhfuns.so /usr/lib/

.PHONY: edit clean

