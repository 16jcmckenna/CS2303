/*	Jonathan Gaines
	PA2		*/


#include <stdio.h>
#include <stdlib.h>

FILE *input;
int k, x, y, gens;












int main(int argc, char *argv[]) {
	if(argc < 5){
		// error in cli
	}

	x = atoi(argv[1]);
	y = atoi(argv[2]);
	gen = atoi(argv[3]);
	input = fopen(argv[4], "r");
	
	if(!input){
		// error in cli
	}



	return 0;
	
}//main
