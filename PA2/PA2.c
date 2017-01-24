/*	Jonathan Gaines
	PA2		*/


#include <stdio.h>
#include <stdlib.h>
#include <cstring>
FILE *input;
int k, x, y, gens;
//int grid[][];
char buff[255];
unsigned int i, j;





int main(int argc, char *argv[]) {
	if(argc < 5){
		// error in cli
	}
	x = atoi(argv[1]);
	y = atoi(argv[2]);


	char grid[y][x];


	gens = atoi(argv[3]);
	input = fopen(argv[4], "r");
	
	
	if(!input){
		// error in cli
	}
	
	
	fscanf(input, "%s", buff);
	char line[] = buff;


	for(int i = 0; i < sizeof(line); i++){
		printf("%s", line[i]);
	}

/*	for(int i = 0; i < strlen(line); i++){
		grid[0][i] = line[i];
	}

	for(int i = 0; i < x; i++){
		printf("%s", grid[0][i]);
	}
*/
	//fscanf(input, "%s", buff);
	//printf("1 : %s\n", buff);

	fclose(input);
	

	return 0;
	
}//main
