#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "operations.h"

/* END GAME FUNCTIONS **************************************************************/

int compare_matrices(int **arr1, int **arr2){
// check if two matrices hold the same values for every element

	int val = 0;
	
	//7. i and j will increment until i is one less than y and j is one less than x
	for (int i = 0; i < y; i++)
    for (int j = 0; j < x; j++)
			if(arr1[i][j] == arr2[i][j]) val++;
	//7. i and j are one less than y and x; all matrix positions have been cycled over

	val = (val == x*y) ? 1 : 0;
	return val;
}//compare_matrices



int stuck_pat(int **cur_arr, int **prev1_arr){
// checks if pattern is stuck by comparing prev1 and current matrices

	if(compare_matrices(cur_arr, prev1_arr))
		return 1;
	else
		return 0;
}//stuck_pat




int repeating_pat(int **cur_arr, int **prev2_arr){
// checks for a repeating pattern by comparing prev2 and current matrices

	if(compare_matrices(cur_arr, prev2_arr))
		return 1;
	else
		return 0;
}//repeating_pat




int all_dead(int **arr){
// check if all grid values are int values 46

	int val = 0;
	//8. i and j will increment until i is one less than y and j is one less than x
  for (int i = 0; i < y; i++)
    for (int j = 0; j < x; j++)
			if(arr[i][j] == 46) val++;
	//8. i and j are one less than y and x; all matrix positions have been cycled over

	val = (val == x*y) ? 1 : 0;
	return val;
}//all_dead



int is_complete(int **arr){
// check if the program should stop producing generations

	if(all_dead(arr))
		return 1;
	else if (stuck_pat(arr, prev1) && cur_gen > 0)
		return 2;
	else if (repeating_pat(arr, prev2) && cur_gen > 1)
		return 3;
	else if(cur_gen == gens)
		return 4;
	else
		return 0;
}//is_complete


/* END END GAME FUNCTIONS************************************************************/




/* NEW GEN FUNCTIONS ****************************************************************/


void write_ops(int **cur_grid, int **var_grid){
//pulls neighbor values for every value in matrix and then births or kills organisms

	//9. i and j will increment until i is one less than y and j is one less than x
	for (int i = 0; i < y; i++)
  	for (int j = 0; j < x; j++){
			int num_neighbors = 0;

			if(i == 0 && j == 0){
				if(cur_grid[i+1][j] == 120)
					num_neighbors++;
				if(cur_grid[i][j+1] == 120)
					num_neighbors++;
				if(cur_grid[i+1][j+1] == 120)
					num_neighbors++;
			}
			else if(i == y-1 && j == x-1){
				if(cur_grid[i-1][j] == 120)
					num_neighbors++;
				if(cur_grid[i][j-1] == 120)
					num_neighbors++;
				if(cur_grid[i-1][j-1] == 120)
					num_neighbors++;
			}
			else if(i == y-1 && j == 0){
				if(cur_grid[i][j+1] == 120)
					num_neighbors++;
				if(cur_grid[i-1][j] == 120)
					num_neighbors++;
				if(cur_grid[i-1][j+1] == 120)
					num_neighbors++;	
			}
			else if(i == 0 && j == x-1){
				if(cur_grid[i+1][j] == 120)
					num_neighbors++;
				if(cur_grid[i][j+1] == 120)
					num_neighbors++;
				if(cur_grid[i][j-1] == 120)
					num_neighbors++;
			}
			else if(i == 0){
				if(cur_grid[i][j+1] == 120)
					num_neighbors++;
				if(cur_grid[i][j-1] == 120)
					num_neighbors++;
				if(cur_grid[i+1][j] == 120)
					num_neighbors++;
				if(cur_grid[i+1][j+1] == 120)
					num_neighbors++;
				if(cur_grid[i+1][j-1] == 120)
					num_neighbors++;
			}
			else if(j == 0){
				if(cur_grid[i+1][j] == 120)
					num_neighbors++;
				if(cur_grid[i-1][j] == 120)
					num_neighbors++;
				if(cur_grid[i][j+1] == 120)
					num_neighbors++;
				if(cur_grid[i+1][j+1] == 120)
					num_neighbors++;
				if(cur_grid[i-1][j+1] == 120)
					num_neighbors++;	
			}
			else if(i == y-1){
				if(cur_grid[i][j-1] == 120)
					num_neighbors++;
				if(cur_grid[i][j+1] == 120)
					num_neighbors++;
				if(cur_grid[i-1][j] == 120)
					num_neighbors++;
				if(cur_grid[i-1][j-1] == 120)
					num_neighbors++;
				if(cur_grid[i-1][j+1] == 120)
					num_neighbors++;	
			}
			else if(j == x-1){
				if(cur_grid[i-1][j] == 120)
					num_neighbors++;
				if(cur_grid[i+1][j] == 120)
					num_neighbors++;
				if(cur_grid[i][j-1] == 120)
					num_neighbors++;
				if(cur_grid[i+1][j-1] == 120)
					num_neighbors++;
				if(cur_grid[i-1][j-1] == 120)
					num_neighbors++;	
			}
			else {
				if(cur_grid[i-1][j] == 120)
					num_neighbors++;
				if(cur_grid[i+1][j] == 120)
					num_neighbors++;
				if(cur_grid[i][j-1] == 120)
					num_neighbors++;
				if(cur_grid[i][j+1] == 120)
					num_neighbors++;
				if(cur_grid[i-1][j+1] == 120)
					num_neighbors++;	
				if(cur_grid[i-1][j-1] == 120)
					num_neighbors++;
				if(cur_grid[i+1][j+1] == 120)
					num_neighbors++;
				if(cur_grid[i+1][j-1] == 120)
					num_neighbors++;
			}
			var_grid[i][j] = num_neighbors;
		}
	//9. i and j are one less than y and x; all matrix positions have been cycled over

	//10. i and j will increment until i is one less than y and j is one less than x
	for (int i = 0; i < y; i++)
  	for (int j = 0; j < x; j++){
			if(var_grid[i][j] == 3 && cur_grid[i][j] == 46)
				var_grid[i][j] = 120;
			else if((var_grid[i][j] == 2 || var_grid[i][j] == 3) && cur_grid[i][j] == 120)
				var_grid[i][j] = 120;
			else if((var_grid[i][j] < 2 || var_grid[i][j] > 3) && cur_grid[i][j] == 120)
				var_grid[i][j] = 46;
			else 
				var_grid[i][j] = cur_grid[i][j];
		} 
	//10. i and j are one less than y and x; all matrix positions have been cycled over

}//write_ops


void write_new(int **cur_grid, int **var_grid, int **prev1_l, int **prev2_l){
//handles matrix operations to create new matrix for new generation

	write_ops(cur_grid, var_grid);
	
	//set grid equal to the variable grid
	//11. i and j will increment until i is one less than y and j is one less than x
  for (int i = 0; i < y; i++)
    for (int j = 0; j < x; j++){
			prev2[i][j] = prev1[i][j];
			prev1[i][j] = grid[i][j];
			cur_grid[i][j] = var_grid[i][j];
		}
	//11. i and j are one less than y and x; all matrix positions have been cycled over
}//write_new


/* END NEW GEN FUNCTIONS ************************************************************/


void print_gen(int **arr){
//prints the current generation

	printf("\nGeneration %d\n\n", cur_gen);

	//12. i and j will increment until i is one less than y and j is one less than x
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++)
			printf("%c ", (char) arr[i][j]);
	//12. i and j are one less than y and x; all matrix positions have been cycled over
		printf("\n");
	}
}//print_gen


void apply_ops(void){
// handles all matrix operations
	char ch;
	
	//13. Cycles until the function is_complete returns a value of 1
	while(!is_complete(grid)){
			if(print){
				print_gen(grid);
				usleep(75*1000);
			}
			if(pause1){
				printf("Press ENTER/RETURN to go to next generation\n");
				scanf("%c", &ch);
				write_new(grid, variable_grid, prev1, prev2);		
			} else {
				write_new(grid, variable_grid, prev1, prev2);		
			}
		
			cur_gen++;
	}
	//13. Game of life is complete
	
	printf("\n%d generations played\n", cur_gen);
	if(is_complete(grid) == 1)
		printf("Termination condition: All organisms dead\n");
	else if(is_complete(grid) == 2)
		printf("Termination condition: Steady state reached\n");
	else if(is_complete(grid) == 3)
		printf("Termination condition: Oscillating reached\n");
	else if(is_complete(grid) == 4)
		printf("Termination condition: Desired generation reached\n");


}//apply_ops

