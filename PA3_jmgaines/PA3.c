/* Jonathan Gaines
	PA3		*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maketmp.h"
#include "makeoutput.h"


int main(int argc, char *argv[]){
	wc = 0;
	unique_wc = 0;

	output = fopen(argv[1], "w+");
	tmp = fopen("tmp.txt", "w+");

	for(int i = 2; i < argc; i++){
		FILE *input;
		input	= fopen(argv[i], "r");
		if(!input){
			printf("Input file not found\n");
			exit(EXIT_FAILURE);
		}
		printInit(input);
		fclose(input);
	}	

	tmp2out();
	
	return 0;
}//main



