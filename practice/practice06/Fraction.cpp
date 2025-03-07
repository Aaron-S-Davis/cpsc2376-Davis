#include "Fraction.h"

Fraction::Fraction(int n, int d) : num(n), den(d) {
	if (d == 0) {
		throw std::runtime_error("Denominator can't be 0!");
	}
	simplify();
}

int Fraction::getNumerator() const {
	return num;
}

int Fraction::getDenominator() const {
	return den;
}

void Fraction::setNumerator(int n) {
	num = n;
}

void Fraction::setDenominator(int d) {
	if (d == 0) {
		throw std::runtime_error("Denominator can't be 0!");
		d = 1;
	}
	den = d;
}

void Fraction::simplify() {
	int a = num, b = den;
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	int gcd = a;

	num /= gcd;
	den /= gcd;
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
	int newNum = (lhs.num * rhs.den) + (rhs.num * lhs.den);
	int newDen = lhs.den * rhs.den;
	return Fraction(newNum, newDen);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
	int newNum = (lhs.num * rhs.den) - (rhs.num * lhs.den);
	int newDen = lhs.den * rhs.den;
	return Fraction(newNum, newDen);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
	int newNum = lhs.num * rhs.num;
	int newDen = lhs.den * rhs.den;
	return Fraction(newNum, newDen);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
	if (rhs.num == 0 || rhs.den == 0) {
		throw std::runtime_error("Can't divide a fraction by zero.");
	}
	int newNum = lhs.num * rhs.den;
	int newDen = lhs.den * rhs.num;
	return Fraction(newNum, newDen);
}

std::ostream& operator<<(std::ostream& out, const Fraction& f) {
	out << f.num << "/" << f.den;
	return out;
}
