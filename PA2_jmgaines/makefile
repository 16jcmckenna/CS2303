# makefile for PA2_jmgaines
# WRITTEN BY: Jonathan Gaines


life: PA2.o operations.o
	gcc -Wall -o life PA2.o operations.o

operations.o: operations.c operations.h 
	gcc -Wall -c operations.c 

PA2.o: operations.h PA2.c
	gcc -Wall -c PA2.c  

clean:
	rm -f PA2.o operations.o life

all: life
