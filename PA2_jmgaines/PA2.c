/*	Jonathan Gaines
	PA2		*/

#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

FILE *input;
int x, y, gens, init_x = 0, init_y = 0;
char buff[255];
int print, pause;
extern int** grid; 


void allocate_2d_mem(void){
	//allocates memory for the 2d array
	grid = (int **)malloc(y*sizeof(int*));
	for(int c = 0; c < y; c++) grid[c] = (int*)malloc(x*sizeof(int));
}//allocate_2d_mem

void initialize_values(FILE *init_config){
	//initialize values in grid[][] to ASCII value of "o"
	for(int i = 0; i < y; i++)
		for(int j = 0; j < x; j++)
			grid[i][j] = (int) 111;


	//overwrite with init configeration and center it in grid
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int x_assign = 0, y_assign = 0, x_start = 0, y_start = 0;


	for(int i = 0; i < 2; i++) {
		while((read = getline(&line, &len, init_config)) != -1){
			if(!i) { // gets length and width of file matrix
				init_x = !init_y ? read-1 : init_x; 
				init_y++;
			} else { // assigns init values to center of grid array
				for(x_assign = x_start; x_assign < init_x + x_start; x_assign++)
					grid[y_assign][x_assign] = line[x_assign-x_start];
				y_assign++;	
			}
		}
		rewind(init_config);//go back to beginning of file
		x_start = (int) x/2 - init_x/2;
		y_start = (int) y/2 - init_y/2;
		y_assign = y_start;
	}

}//initialize_values

void print_grid(void){
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++)
			printf("%c ", (char) grid[i][j]);

		printf("\n");
	}
	
}//print_grid


int main(int argc, char *argv[]) {
	
	if(argc < 5) exit(EXIT_FAILURE); // if there's not enough args, throw error
	x = atoi(argv[1]);
	y = atoi(argv[2]);
	gens = atoi(argv[3]);
	input = fopen(argv[4], "r");
	
	if(!input) exit(EXIT_FAILURE);

	
	
	allocate_2d_mem();
	initialize_values(input);
	print_grid();
	

	fclose(input);

	return 0;
}//main
