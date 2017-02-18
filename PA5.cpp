/*
 * PA5.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: ywu
 */

#include <iostream>
#include "Rational.h"
#include "string.h"
using namespace std;

void processInput(ifstream &input);

int main(int argc, char *argv[]) {

	/* Argument Handling Section*/
	if (argc < 2) { // expect at least an file_input file.
		printf("Error: Too Few Arguments\n");
		exit(EXIT_FAILURE);
	} else {
		// argument format:
		// program(0) inputfile(1) ...
		// file input starts at index 1.
		for (int i = 1; i < argc; i++) {
			ifstream file_input(argv[i]); // argv[0] is program name argv[1] is the start of arguments
			if (!file_input) { // error handling for file unable to be open
				printf("Error: Unable To Open File\n");
				exit(EXIT_FAILURE);
			}
			cout << "Input File: " << argv[i] << endl;
			processInput(file_input);
		}
	}
}
void processInput(ifstream &input) {
	int line_cnt = 1;
	while (input.peek() != EOF) {

		Rational r1;

		bool isBool = false;
		bool out_bool = false;

		input >> r1;
		cout << "L" << line_cnt << ": " << r1 << " ";

		while (input.peek() != '\n' && input.peek() != EOF) {
			string operation;
			Rational r2;
			input >> r2;
			input >> operation;
			cout << r2 << " " << operation << " ";
			if (operation == "+") {
				r1 += r2;
				isBool = false;
			} else if (operation == "-") {
				r1 -= r2;
				isBool = false;
			} else if (operation == "*") {
				r1 *= r2;
				isBool = false;
			} else if (operation == "/") {
				r1 /= r2;
				isBool = false;
			} else if (operation == "==") {
				out_bool = r1 == r2;
				isBool = true;
			} else if (operation == "!=") {
				out_bool = r1 != r2;
				isBool = true;
			} else if (operation == "<") {
				out_bool = r1 < r2;
				isBool = true;
			} else if (operation == "<=") {
				out_bool = r1 <= r2;
				isBool = true;
			} else if (operation == ">") {
				out_bool = r1 > r2;
				isBool = true;
			} else if (operation == ">=") {
				out_bool = r1 >= r2;
				isBool = true;
			}
		}
		// removes the newline character unless end of file.
		if (input.peek() != EOF) {
			input.get();
		}
		// print output based on boolean or double result;
		if (isBool) {
			cout << "\t: " << boolalpha << out_bool << noboolalpha << endl;
		} else {
			cout << "\t: " << r1 << " (double " << r1.toDouble() << ")" << endl;
		}
		//ignore new line char
		line_cnt++; // increase line count, move to next line
	}
}
