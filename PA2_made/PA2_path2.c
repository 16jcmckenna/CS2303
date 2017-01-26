/*	Jonathan Gaines
	PA2		*/


#include <stdio.h>
#include <stdlib.h>


FILE *input;
int x, y, gens;
char buff[255];
int print, pause;



void allocate_2d_mem(int*** grid){
//allocates memory for the 2d array
	*grid = (int**)malloc(x*sizeof(int*));
	for(int c = 0; c < x; c++) (*grid)[c] = (int*)malloc(y*sizeof(int));
}//allocate_2d_mem


int main(int argc, char *argv[]) {
	
	if(argc < 5) exit(EXIT_FAILURE); // if there's not enough args, throw error
	x = atoi(argv[1]);
	y = atoi(argv[2]);
	gens = atoi(argv[3]);
	input = fopen(argv[4], "r");
	
	if(!input) exit(EXIT_FAILURE);

	int** grid; 
	
	allocate_2d_mem(&grid);


	fclose(input);

	return 0;
}//main
