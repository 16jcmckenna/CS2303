/*	Jonathan Gaines
	PA2		*/

#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

FILE *input;
int x, y, gens;
char buff[255];
int print, pause;
int **grid, **variable_grid, **prev1, **prev2; 


int** allocate_2d_mem(FILE *init_config){
	//allocates memory for the 2d array

	int i, **arr;
	arr = malloc(y*sizeof(int*));
	for(i = 0; i < y; i++) arr[i] = malloc(x*sizeof(int));


	for(int i = 0; i < y; i++)
		for(int j = 0; j < x; j++)
			arr[i][j] = (int) 111;

	
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int init_y = 0;
	int x_assign = 0, y_assign = 0;
	int x_start = 0, y_start = 0;
	int x_greatest = 0;
	int line_lengths[y];
	
	
	for(int i = 0; i < 2; i++) {
		while((read = getline(&line, &len, init_config)) != -1){
			if(!i) { // gets length and width of file matrix
				line_lengths[init_y] = read-1;
				x_greatest = x_greatest < read-1 ? read-1 : x_greatest;

				init_y++;
			} else { // assigns init values to center of grid array
				for(x_assign = x_start; x_assign < line_lengths[y_assign-y_start] + x_start; x_assign++)
					arr[y_assign][x_assign] = line[x_assign-x_start];
				y_assign++;	
			}
		}
		rewind(init_config);//go back to beginning of file
		x_start = (int) x/2 - x_greatest/2;
		y_start = (int) y/2 - init_y/2;
		y_assign = y_start;
	}


	return arr;
}//allocate_2d_mem




void print_grid(void){
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++)
			printf("%c ", (char) prev1[i][j]);

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

	grid 	= allocate_2d_mem(input);		prev1 = allocate_2d_mem(input); 
	variable_grid = allocate_2d_mem(input);		prev2 = allocate_2d_mem(input);
	
	print_grid();	

	fclose(input);

	return 0;
}//main
