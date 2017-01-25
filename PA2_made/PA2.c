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
	char grid[x][y];
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


	for(int a = 0; a <= x; a++){
		for(int b = 0; b <= y; b++){
			grid[a][b] = (char) 111;		
		}
	}


	int x_assign, y_assign = 0;

	while((read = getline(&line, &len, input)) != -1) {
		j = !k ? read-1 : j; // set j = read if its the first pass through the while loop
		
		for(x_assign = 0; x_assign < j; x_assign++) {
			grid[y_assign][x_assign] = line[x_assign];
		}
		k++;
		y_assign = k;
	}
	
	for(int a = 0; a < x; a++){
		for(int b = 0; b < y; b++){
			printf(" %c", grid[a][b]);
		}
		printf("\n");
	}
	


	






/*									
	int x_assign, y_assign = 0;
	while(EOF != fgets(buff, 255, (FILE*)input) && y_assign < y){

		// find sizeof line() and set j equal to that
		// set y_assign equal to k
		// center given values in grid[][]
		
		char *line;
		line = malloc(sizeof(char) * x);
		line = buff;	
		
		j = sizeof(line) / sizeof(line[0]); 

		for(x_assign = 0; x_assign < x; x_assign++){
			grid[x_assign][y_assign] = line[x_assign];
		}
		

		for(int i = 0; i < j; i++){
			printf("%c\n", line[i]);
		}
		y_assign++;
	}

 PRINTS OUT VALUE OF GRID[][] 
	for(int a = 0; a < j; a++){
		for(int b = 0; b < y; b++){
			printf("%c", (char) grid[b][a]);
		}
		printf("\n");
	}
*/


	fclose(input);
	

	return 0;
	
}//main
