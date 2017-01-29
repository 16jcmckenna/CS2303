#include <stdio.h>
#include <stdlib.h>
#include "operations.h"


// if main grid = prev1 or prev2, stop
// apply all changes between to variable_grid, then write varaible_grid to main grid

int compare_matrices(int **arr1, int **arr2){
// check if two matrices hold the same value
	int val = 0;
	
	for (int i = 0; i < y; i++)
    for (int j = 0; j < x; j++)
			if(arr1[i][j] == arr2[i][j]) val++;

	val = (val == x*y) ? 1 : 0;
	return val;
}//compare_matrices

int stuck_pat(int **cur_arr, int **prev1_arr){
	if(compare_matrices(cur_arr, prev1_arr))
		return 1;
	else
		return 0;
}//stuck_pat


int repeating_pat(int **cur_arr, int **prev2_arr){
	if(compare_matrices(cur_arr, prev2_arr))
		return 1;
	else
		return 0;
}//repeating_pat


int all_dead(int **arr){
// check if all grid values are int values 111
	int val = 0;

  for (int i = 0; i < y; i++)
    for (int j = 0; j < x; j++)
			if(arr[i][j] == 111) val++;
		
	val = (val == x*y) ? 1 : 0;
	return val;
}//all_dead


int is_complete(int **arr){
// check if the program should stop producing generations
	if(all_dead(arr))
		return 1;
	else if (stuck_pat(arr, prev1) && cur_gen > 0)
		return 1;
	else if (repeating_pat(arr, prev2) && cur_gen > 1)
		return 1;
	else if(cur_gen == gens)
		return 1;
	else 
		return 0;
}//is_complete


void print_gen(int **arr){
	printf("\nGeneration %d\n", cur_gen);
	
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++)
			printf("%c ", (char) arr[i][j]);

		printf("\n");
	}
}//print_gen


void apply_ops(void){
// handle all matrix operations
	while(!is_complete(grid)){
			print_gen(grid);
				
			cur_gen++;
	}

	printf("%d generations printed\n", cur_gen);
}//apply_ops

