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
			// print out the current file name.
			cout << "Input File: " << argv[i] << endl;
			// read in the lines of the input and perform calculations.
			processInput(file_input);
			// close current file when done.
			file_input.close();
		}
	}
}
/**
 * Print out all lines of input from file.
 * @param input The istream.
 */
void processInput(ifstream &input) {
	int line_cnt = 1; // the line being read.
	// loops while the eof has not been reached or \n is not next (for empty lines)
	while (input.peek() != '\n' && input.peek() != EOF) {
		/* LOOP LOGIC
		 * Since the input is of the format r1 (r2 op1) (r3 op2).. (r_n op_n)
		 * the solution is to first assign r1 and loop through
		 * assigning another r and op since those are the repeating events.
		 */
		Rational r1; // declare first rational.
		// declare boolean case output vars
		bool isBool = false;
		bool out_bool = false;

		input >> r1; // read in first rational.
		// print first part of the output.
		cout << "L" << line_cnt << ": " << r1 << " ";
		// continue with the loop logic for the repeating
		while (input.peek() != '\n' && input.peek() != EOF) {
			// declare rational 2 and operation
			Rational r2;
			string operation;
			// read in both rational 2 and operation
			input >> r2;
			input >> operation;
			// output both rational 2 and operation
			cout << r2 << " " << operation << " ";
			// check what operation to apply.
			// and whether boolean or double output.
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
			} else if (operation == "+=") {
				r1 += r2;
				isBool = false;
			} else if (operation == "-=") {
				r1 -= r2;
				isBool = false;
			} else if (operation == "*=") {
				r1 *= r2;
				isBool = false;
			} else if (operation == "/=") {
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
