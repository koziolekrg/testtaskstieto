C=gcc
CFLAGS=-Wall
LDLIBS=-lm

all: main

main: main.o
	$(CC) $(CFLAGS) -o main main.o $(LDLIBS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

