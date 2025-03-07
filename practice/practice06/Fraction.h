#pragma once

#include <iostream>
#include <stdexcept>

class Fraction {
public:
	//constructor
	Fraction(int n = 0, int d = 1);

	//getters
	int getNumerator() const;
	int getDenominator() const;

	//setters
	void setNumerator(int n);
	void setDenominator(int d);

	//helper function
	void simplify();

	//friend function
	friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
private:
	int num;
	int den;
};
