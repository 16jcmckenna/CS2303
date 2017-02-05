#makefile for PA3_jmgaines
# WRITTEN BY: Jonathan Gaines

word-count: PA3.o
	gcc -Wall -o word-count PA3.o

PA3.o: PA3.c
	gcc -Wall -c PA3.c

clean:
	rm -f PA3.o word-count

all: word-count
