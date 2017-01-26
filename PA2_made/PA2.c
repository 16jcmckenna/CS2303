/*	Jonathan Gaines
	PA2		*/


#include <stdio.h>
#include <stdlib.h>


FILE *input;
int k, x, y, gens;
char buff[255], chr;
int print, pause;
int j = 0, k = 0;




int main(int argc, char *argv[]) {
	if(argc < 5){
		// error in cli
	}
	x = atoi(argv[1]);
	y = atoi(argv[2]);
	char *grid = malloc(y * sizeof(char));
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	gens = atoi(argv[3]);
	input = fopen(argv[4], "r");
	//printf("%d", sizeof(argv)/sizeof(char));	
	//print = (strcmp(argv[5], "print") || !((sizeof(argv)/sizeof(char)) < 5)) ? 0 : 1;
	//pause = (strcmp(argv[6], "pause") || !((sizeof(argv)/sizeof(char)) < 6)) ? 0 : 1;

	if(!input){
		exit(EXIT_FAILURE);	
	}

// set init values of array to 'o'
//	for(int a = 0; a <= x; a++){
		for(int b = 0; b <= y; b++){
			char line_create[x];
			for(int a = 0; a <= x; a++){
				line_create[a] = (char) 111;
			}
			grid[b] = line_create;	
			//printf("%s\n", line_create);
		}
//	}

	for(int i = 0; i <= y; i++){
		printf("%s\n", grid[i]);
	}

// get number of lines and character width in file
	while((read = getline(&line, &len, input)) != -1) {
		// set j = read if its the first pass through the while loop
		j = !k ? read-1 : j; 		
		k++;
	}
	rewind(input);


// overwrite previously set values with values from input file
	int x_assign = 0, y_assign = 0, x_start = 0, y_start = 0;

	y_start = (int) x/2 - j/2 + 1;
	x_start = (int) y/2 - k/2 - 1;
	y_assign = y_start;

	while((read = getline(&line, &len, input)) != -1) {
		/*for(x_assign = x_start; x_assign < j + x_start; x_assign++) {
			grid[y_assign][x_assign] = line[x_assign-x_start];
		}*/

		grid[y_assign] = line;
		y_assign++;
	}
	
	
/*	for(int a = 0; a < x; a++){
		for(int b = 0; b < y; b++){
			printf(" %c", grid[a][b]);
		}
		printf("\n");
	}
*/	



	fclose(input);
	

	return 0;
	
}//main
