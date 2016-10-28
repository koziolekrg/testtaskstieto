C=gcc
CFLAGS=-Wall
LDLIBS=-lm

all: main

main: main.o splitter.o
	$(CC) $(CFLAGS) -o main main.o splitter.o $(LDLIBS)

main.o: main.c splitter.h
	$(CC) $(CFLAGS) -c main.c

splitter.o: splitter.c
	$(CC) $(CFLAGS) -c splitter.c
