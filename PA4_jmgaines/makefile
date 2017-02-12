# makefile for PA4_jmgaines
# WRITTEN BY: Jonathan Gaines

qSim: Event.o Customer.o Teller.o PA4.o
	g++ -Wall -o qSim PA4.o Event.o Teller.o Customer.o

Customer.o: Customer.cpp Customer.h Teller.h Event.h
	g++ -Wall -c -g Customer.cpp

Teller.o: Teller.cpp Teller.h Customer.h Event.h
	g++ -Wall -c -g Teller.cpp

Event.o: Event.cpp Teller.h Customer.h Event.h
	g++ -Wall -c -g Event.cpp

PA4.o: Customer.h Teller.h Event.h PA4.cpp
	g++ -Wall -c -g PA4.cpp

clean:
	rm -f qSim Customer.o Teller.o Event.o PA4.o

all: qSim
