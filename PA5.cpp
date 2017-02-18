/*
 * PA5.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: ywu
 */

#include <iostream>
#include "Rational.h"
using namespace std;

int main(int argc, char *argv[]) {

	FILE *file_input; // declare file pointer

	/* Argument Handling Section*/
	if (argc < 2) { // expect at least an file_input file.
		printf("Error: Too Few Arguments\n");
		exit(EXIT_FAILURE);
	} else {
		// argument format:
		// program(0) inputfile(1) ...
		// file input starts at index 1.
		for (int i = 1; i < argc; i++) {
			file_input = fopen(argv[i], "r"); // argv[0] is program name argv[1] is the start of arguments
			if (!file_input) { // error handling for file unable to be open
				printf("Error: Unable To Open File\n");
				exit(EXIT_FAILURE);
			}
			fclose(file_input);
		}
	}
	Rational r1 = Rational(10, -2);

	Rational r2 = Rational(-20, -1);

	cout << r1 << endl;
	cout << r2 << endl;

	r2 = r1;

	cout << r1 << endl;
//	//cin >> r1;
//	r1.normalize(r1.getNumerator(), r1.getDenominator());
//	cout << r1 << endl;

	return 0;
}
