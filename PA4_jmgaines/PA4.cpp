//==========================================================================
// Name        : PA4.cpp
// Author      : Jonathan Gaines
//==========================================================================

#include <iostream>
#include <cstdlib>
#include "Event.h"
#include "Customer.h"
#include "Teller.h"

using namespace std;

int num_customers;
int num_tellers;
int sim_time;
float avg_serv_time;

struct eventQueue {
	int queue_number; 
	eventQueue *next;
};

// runs simulation and collects/prints data
void runSim(){
	
}//runSim

int main(int argc, char *argv[]) {

	if(argc < 5) {
		cout << "You are missing one or more arguments" << endl;
		exit(EXIT_FAILURE);
	}

	num_customers = atoi(argv[1]);
	num_tellers 	= atoi(argv[2]);
	sim_time			= atoi(argv[3]);
	avg_serv_time = atoi(argv[4]);

	runSim();

	return 0;
}//main

