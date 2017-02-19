# makefile for PA4_jmgaines
# WRITTEN BY: Jonathan Gaines

PA5: Rational.o PA5.o
	g++ -Wall -o PA5 Rational.o PA5.o

Rational.o: Rational.cpp Rational.h
	g++ -Wall -c -g Rational.cpp

PA5.o: PA5.cpp Rational.h
	g++ -Wall -c -g PA5.cpp

clean:
	rm -f PA5 Rational.o PA5.o

all: PA5 
