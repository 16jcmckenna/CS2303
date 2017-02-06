#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "maketmp.h"
#include "makeoutput.h"

void printInit(FILE *f){
	while(fscanf(f, "%255s", word) == 1){
		for(int i = 0; word[i]; i++){
			word[i] = tolower(word[i]);
		}
	
		removePunc(word);

		if(word[0] != 45)
			fprintf(tmp, "%s \n", word);

	}
}//printInit

void tmp2out(void){
	fclose(tmp);
	tmp = fopen("tmp.txt", "r");

	readWords(tmp);
	
	fclose(output);
	fclose(tmp);
	remove("tmp.txt");
}//reopenTmp

void removePunc(char arr[256]){
	int cur_pos= 0;
	for(char *c = word; *c; c++){
		int n = *c;
		if((isalpha(*c)) || n == 39 || n == 45){
			arr[cur_pos++] = *c;
		}
	}
	arr[cur_pos] = '\0';
}//removePunc
