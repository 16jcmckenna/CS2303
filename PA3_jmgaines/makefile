# makefile for PA3_jmgaines
# WRITTEN BY: Jonathan Gaines

word-count: maketmp.o makeoutput.o PA3.o
	gcc -Wall -o word-count PA3.o maketmp.o makeoutput.o

makeoutput.o: makeoutput.c makeoutput.h maketmp.h
	gcc -Wall -c -g makeoutput.c

maketmp.o: maketmp.c maketmp.h
	gcc -Wall -c -g maketmp.c

PA3.o: maketmp.h makeoutput.h PA3.c
	gcc -Wall -c -g PA3.c

clean:
	rm -f PA3.o maketmp.o makeoutput.o word-count

all: word-count
