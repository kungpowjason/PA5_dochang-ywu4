/*
 * Rational.h
 *
 *  Created on: Feb 15, 2017
 *      Author: ywu
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

#include "iostream"
#include "fstream"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Rational {
	friend ostream& operator <<(ostream& outs, const Rational &a);
	friend istream& operator >>(istream& ins, Rational &a);

public:
	// Constructors and Destructor
	Rational();
	Rational(const int wholeNumber);
	Rational(const int num, const int denom);
	Rational(const Rational &a);
	~Rational();

	bool operator ==(const Rational &a) const;
	bool operator !=(const Rational &a) const;
	bool operator <(const Rational &a) const;
	bool operator <=(const Rational &a) const;
	bool operator >(const Rational &a) const;
	bool operator >=(const Rational &a) const;
	Rational operator +(const Rational &a);
	Rational operator -(const Rational &a);
	Rational operator *(const Rational &a);
	Rational operator /(const Rational &a);
	Rational &operator =(const Rational &a);
	Rational &operator +=(const Rational &a);
	Rational &operator -=(const Rational &a);
	Rational &operator *=(const Rational &a);
	Rational &operator /=(const Rational &a);

	double toDouble() const;
	Rational &normalize(long long int num, long long int denom);
	long long int gcd(long long int a, long long int b) const;

	int getDenominator() const;
	void setDenominator(int denominator);
	int getNumerator() const;
	void setNumerator(int numerator);
private:
	// The two integers that make up a Rational number.
	int numerator;
	int denominator;

};

#endif /* RATIONAL_H_ */
