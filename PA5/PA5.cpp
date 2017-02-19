#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <string>
#include "Rational.h"

using namespace std;

int main(int argc, char* argv[]){
	
	// cycle through variable amount of input files

	if(argc == 1){
		cout << "No input files given" << endl;
		exit(EXIT_FAILURE);
	}
	
	for(int i = 1; i < argc; i++){
		ifstream input(argv[i]);
	
		if(!input.is_open()){
			cout << "Error opening file \"" << argv[i] << "\"" << endl;
			exit(EXIT_FAILURE);
		}

		string line;

		while(getline(input, line)){
			cout << line << endl;
		}

		input.close();
	}


	return 0;
}//main
