/*	Jonathan Gaines
	PA2		*/


#include <stdio.h>
#include <stdlib.h>


FILE *input;
int x, y, gens;
char buff[255];
int print, pause;
int** grid; 


void allocate_2d_mem(void){
//allocates memory for the 2d array
	grid = (int **)malloc(y*sizeof(int*));
	for(int c = 0; c < y; c++) grid[c] = (int*)malloc(x*sizeof(int));
}//allocate_2d_mem

void initialize_values(void){
//initialize values in grid[][] to ASCII value of "o"
	for(int i = 0; i < y; i++)
		for(int j = 0; j < x; j++)
			grid[i][j] = (int) 111;
}//initialize_values

void print_init(void){
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++)
			printf("%c ", (char) grid[i][j]);

		printf("\n");
	}
	
}//print_init


int main(int argc, char *argv[]) {
	
	if(argc < 5) exit(EXIT_FAILURE); // if there's not enough args, throw error
	x = atoi(argv[1]);
	y = atoi(argv[2]);
	gens = atoi(argv[3]);
	input = fopen(argv[4], "r");
	
	if(!input) exit(EXIT_FAILURE);

	
	
	allocate_2d_mem();
	initialize_values();
	print_init();

	fclose(input);

	return 0;
}//main
