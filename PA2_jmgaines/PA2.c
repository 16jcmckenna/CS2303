/*	Jonathan Gaines
	PA2		*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

FILE * input;
char buff[255];

int** allocate_2d_mem(FILE *init_config) {
    //allocates memory for the 2d array

    int i, **arr;
    arr = malloc(y * sizeof(int * ));
    
		//1. y contains length of matrix, i increments while it is less than y
		for (i = 0; i < y; i++) arr[i] = malloc(x * sizeof(int));
		//1. memory allocated for y length and i is 1 less than y

		//2. i and j will increment until i is one less than y and j is one less than x
    for (int i = 0; i < y; i++)
      for (int j = 0; j < x; j++)
        arr[i][j] = (int) 46;
		//2. i and j are one less than y and x; all matrix positions have been cycled over

    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int init_y = 0;
    int x_assign = 0, y_assign = 0;
    int x_start = 0, y_start = 0;
    int x_greatest = 0;
    int line_lengths[y];

		//3. i equals zero and will loop twice
    for (int i = 0; i < 2; i++) {
			
			//4. read equals the current line, and the loop will cycle while it hasn't reached 
			// the last line in the file
      while ((read = getline( &line, &len, init_config)) != -1) {
        if (!i) { // gets length and width of file matrix
          line_lengths[init_y] = read - 1;
          x_greatest = x_greatest < read - 1 ? read - 1 : x_greatest;

					if(line_lengths[init_y] > x){
						printf("ERROR: x value less than what is stored in input file\n");
						exit(EXIT_FAILURE);
					}

          init_y++;
        } else { // assigns init values to center of grid array
          
					//5. x_assign equals the starting value of x which was assigned the first time 
					//through the parent for loop and will increment until the line_length of the 
					//given line is reached
					for (x_assign = x_start; 
							x_assign < line_lengths[y_assign - y_start] + x_start; x_assign++)
            arr[y_assign][x_assign] = line[x_assign - x_start];
          y_assign++;
					//5. x_assign has reached the line_length[] array value
        }
      }
			//4. read equals -1 and exits the while loop

      rewind(init_config); //go back to beginning of file
      x_start = (int) x / 2 - x_greatest / 2;
      y_start = (int) y / 2 - init_y / 2;
      y_assign = y_start;
    }
		//3. i equals 2 now and will therefore no longer cycle
	

	  //6. i and j will increment until i is one less than y and j is one less than x
		//reassign o's to .'s
		for (int i = 0; i < y; i++)
     for (int j = 0; j < x; j++)
       if(arr[i][j] == 111) arr[i][j] = 46;
		//6. i and j are one less than y and x; all matrix positions have been cycled over


    return arr;
} //allocate_2d_mem


int main(int argc, char *argv[]) {
		
		// if there's not enough args, throw error
    if (argc < 5){
			printf("ERROR: Not enough arguments\n"); 
			exit(EXIT_FAILURE);
    }

		x = atoi(argv[1]);			y = atoi(argv[2]);
    gens = atoi(argv[3]);		input = fopen(argv[4], "r");

		// if input file does not exist, throw error
    if (!input){
			printf("ERROR: Input file does not exist\n"); 
			exit(EXIT_FAILURE);	
		}

		if (argc < 6){
			print = 0;
			pause1 = 0;
		}
		else if (argc < 7){
			print = strcmp(argv[5], "y") ? 0 : 1;
			pause1 = 0;
		}
		else {
			print = strcmp(argv[5], "y") ? 0 : 1;
			pause1 = strcmp(argv[6], "y") ? 0 : 1;
		}

		cur_gen = 0;
    grid = allocate_2d_mem(input);						prev1 = allocate_2d_mem(input);
		variable_grid = allocate_2d_mem(input);		prev2 = allocate_2d_mem(input);
		
		apply_ops();
		
    fclose(input);

    return 0;
} //main
