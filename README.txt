=============================================================================
Name        : PA5.c
Author      : Yu-sen Wu Dominic Chang
Version     :
Copyright   :
Description : A class of Rational numbers and a test program on 		operators overloaded in the class
=============================================================================
=============================================================================
					Abstract
=============================================================================

=============================================================================
					PA5
=============================================================================

PA5 consist of a rational class that holds two member variables, numerator and
denominator. A variety of operators are overloaded for the class to provide an intuitive interface
for manipulating variables.

=============================================================================
					How To Run
=============================================================================

1. make
2. ./PA5 input_1 input_2 .. input_n

**output to terminal**

=============================================================================
					General Notes
=============================================================================

The input file format is: rational rational op rational op...
Ex. 5/2 5 +
	6/2 7 - 4/5 *
	
If an error is met a print error statement will be made. and continue on to the
next line.
	
************
For boolean cases, since it was not specified, we have decided that if you
do 3 5 < 5 < it will return true because true will be considered equivalent to 1.
************

=============================================================================
					Testing
=============================================================================

The tests and outputs have been put into a test folder. They test for

1) normal operations
2) division by 0, -0, # not 0
3) numerator 0, -0, # not 0

Normalization happens in the constructors and after operations.

For the assignment operator =, it cannot accept itself as an argument.

=============================================================================
References
=============================================================================
1) http://codereview.stackexchange.com/questions/66711/greatest-common-divisor

The algorithm finds the greatest common diviser of either the numerator or denominator in order to find
a number that will not generate any decimal numbers. Basically it recursively checks either the denominator
or numerator modulo the other has a remainder of 0. If that condition happens, then a common diviser has
been found.
