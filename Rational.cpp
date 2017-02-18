/*
 * Rational.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: ywu
 */

#include "Rational.h"
/**
 * Constructor for Rational.
 */
Rational::Rational() {
	numerator = 0;
	denominator = 1;
}
/**
 * Overloaded copy constructor.
 * @param a The rational object to be copied.
 */
Rational::Rational(const Rational &a) {
	numerator = a.numerator;
	denominator = a.denominator;
}
/**
 * Overloaded constructor for Rational.
 * @param wholeNumber The numerator with denominator equal 1.
 */
Rational::Rational(const int wholeNumber) {
	numerator = wholeNumber;
	denominator = 1;
}
/**
 * Overloaded constructor for Rational.
 * @param num The numerator.
 * @param denom The denominator.
 */
Rational::Rational(const int num, const int denom) :
		numerator(num) {
	if (denom == 0) {
		cout << "Error: Denominator cannot be 0." << endl;
		exit(0);
	} else {
		denominator = denom;
	}
	this->normalize(num, denom);
}
/**
 * Destructor for Rational.
 */
/**
 * Getter for denomintor.
 * @return
 */
int Rational::getDenominator() const {
	return denominator;
}
/**
 * Setter for denominator.
 * @param denominator
 */
void Rational::setDenominator(int denominator) {
	this->denominator = denominator;
}
/**
 * Getter for numerator.
 * @return
 */
int Rational::getNumerator() const {
	return numerator;
}
/**
 * Setter for Numerator.
 * @param numerator
 */
void Rational::setNumerator(int numerator) {
	this->numerator = numerator;
}
Rational::~Rational() {
}
/**
 * Overloaded Operator <<.
 * @param outs The output stream.
 * @param a The Rational object to be output.
 * @return The output stream.
 */
ostream &operator <<(ostream &outs, const Rational &a) {
	outs << a.numerator << "/" << a.denominator;
	return outs;
}
/**
 * Overloaded Operator >>.
 * @param ins The input stream.
 * @param a The Rational to be written to.
 * @return
 */
istream &operator >>(istream &ins, Rational &a) {
	char *buf = new char[256];
	char *num;
	char *denom;
	ins.getline(buf, 256);
	num = strtok(buf, " /");
	denom = strtok(NULL, "\n");
	a.setNumerator(atoi(num));
	if (denom != NULL) {
		a.setDenominator(atoi(denom));
	}
	return ins;
}
/**
 * Overloaded operator ==.
 * @param a The Rational number to compare to.
 * @return 1 if equal and 0 if not.
 */
bool Rational::operator ==(const Rational &a) const {
	return (this->toDouble() == a.toDouble());
}
/**
 * Overloaded operator !=.
 * @param a The Rational number to compare to.
 * @return 1 if not equal and 0 if equal.
 */
bool Rational::operator !=(const Rational &a) const {
	return (this->toDouble() != a.toDouble());
}
/**
 * Overloaded operator <.
 * @param a The Rational number to compare to.
 * @return 1 if less than and 0 if else.
 */
bool Rational::operator <(const Rational &a) const {
	return (this->toDouble() < a.toDouble());
}
/**
 * Overloaded operator <=.
 * @param a The Rational number to compare.
 * @return 1 if less than or equal to and 0 if else.
 */
bool Rational::operator <=(const Rational &a) const {
	return (this->toDouble() <= a.toDouble());
}
/**
 * Overloaded operator >.
 * @param a The Rational number to compare to.
 * @return 1 if greater than and 0 if else.
 */
bool Rational::operator >(const Rational &a) const {
	return (this->toDouble() > a.toDouble());
}
/**
 * Overloaded operator >=.
 * @param a The Rational number to compare.
 * @return 1 if greater than or equal to and 0 if else.
 */
bool Rational::operator >=(const Rational &a) const {
	return (this->toDouble() >= a.toDouble());
}
/**
 * Overloaded operator +;
 * @param a The Rational number to add.
 * @return The Rational sum.
 */
Rational Rational::operator +(const Rational &a) {
	long long int common_denom = this->denominator * a.denominator;
	long long int num1 = a.denominator * this->numerator;
	long long int num2 = this->denominator * a.numerator;
	long long int num_sum = num1 + num2;
	Rational r;
	r.normalize(num_sum, common_denom);
	return r;
}
/**
 * Overloaded operator -;
 * @param a The Rational number to subtract.
 * @return The Rational difference.
 */
Rational Rational::operator -(const Rational &a) {
	long long int common_denom = this->denominator * a.denominator;
	long long int num1 = a.denominator * this->numerator;
	long long int num2 = this->denominator * a.numerator;
	long long int num_sum = num1 - num2;
	Rational r;
	r.normalize(num_sum, common_denom);
	return r;
}
/**
 * Overloaded operator *;
 * @param a The Rational number to multiple.
 * @return The Rational product.
 */
Rational Rational::operator *(const Rational &a) {
	long long int num = this->numerator * a.numerator;
	long long int denom = this->denominator * a.denominator;
	Rational r;
	r.normalize(num, denom);
	return r;
}
/**
 * Overloaded operator /;
 * @param a The Rational number to divide.
 * @return The Rational quotient.
 */
Rational Rational::operator /(const Rational &a) {
	long long int num = this->numerator * a.denominator;
	long long int denom = this->denominator * a.numerator;
	Rational r;
	r.normalize(num, denom);
	return r;
}
/**
 * Overloaded operator =;
 * @param a The Rational number used for assignment.
 * @return The Rational the object modified..
 */
Rational &Rational::operator =(const Rational &a) {
	//if the right side is the same as the left side
	if (this == &a) {
		return *this;
	} else {
		this->numerator = a.numerator;
		this->denominator = a.denominator;
		return *this;
	}
}
/**
 * Overloaded operator +=;
 * @param a The Rational number to add.
 * @return The Rational the object modified..
 */
Rational &Rational::operator +=(const Rational &a) {
	Rational r = *this + a;
	this->numerator = r.numerator;
	this->denominator = r.denominator;
	return *this;
}
/**
 * Overloaded operator -=;
 * @param a The Rational number to subtract.
 * @return The Rational the object modified..
 */
Rational &Rational::operator -=(const Rational &a) {
	Rational r = *this - a;
	this->numerator = r.numerator;
	this->denominator = r.denominator;
	return *this;
}
/**
 * Overloaded operator *=;
 * @param a The Rational number to multiply.
 * @return The Rational the object modified..
 */
Rational &Rational::operator *=(const Rational &a) {
	Rational r = *this * a;
	this->numerator = r.numerator;
	this->denominator = r.denominator;
	return *this;
}
/**
 * Overloaded operator /=;
 * @param a The Rational number to divide.
 * @return The Rational the object modified..
 */
Rational &Rational::operator /=(const Rational &a) {
	Rational r = *this / a;
	this->numerator = r.numerator;
	this->denominator = r.denominator;
	return *this;
}
/**
 * Convert Rational number to double.
 * @return The double equivalent.
 */
double Rational::toDouble() const {
	double num = numerator;
	double denom = denominator;
	double val = num / denom;
	return val;
}
/**
 * Find the greater common divider between 2 numbers.
 * @param a First number.
 * @param b Second number.
 * @return The GCF.
 */
long long int Rational::gcd(long long int a, long long int b) const {
	if (a == 0)
		return b;
	return gcd(b % a, a);

}
/**
 * Normalizes the numerator and denominator.
 * @param num Numerator to normalize.
 * @param denom Denominator to normalize.
 * @return The normalize Rational.
 */
Rational &Rational::normalize(long long int num, long long int denom) {
	long long int gcd = this->gcd(num, denom);
	// sign true = positive, false = negative;
	bool sign = (num * denom > -1);
	numerator = num / gcd;
	denominator = denom / gcd;
	if (sign) { // case positive
		numerator = abs(numerator);
	} else if (numerator > -1) { // case negative
		numerator = -numerator;
	}
	denominator = abs(denominator);
	return *this;
}
