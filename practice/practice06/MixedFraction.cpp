#include "MixedFraction.h"

MixedFraction::MixedFraction(int whole, int n, int d) : whole(whole), Fraction(n, d) {
	if (d == 0) {
		throw std::runtime_error("Denominator can't be 0!");
		n = 0;
		d = 1;
	}
}

MixedFraction::MixedFraction(const Fraction& fraction) : whole(whole), Fraction(fraction) {
	whole = getNumerator() / getDenominator();
	int newNum = getNumerator() % getDenominator();
	setNumerator(newNum);
}

std::ostream& operator<<(std::ostream& out, const MixedFraction& mf) {
	if (mf.whole != 0) {
		if (mf.getNumerator() != 0) {
			out << mf.whole << " " << mf.getNumerator() << "/" << mf.getDenominator();
		}
		else {
			out << mf.whole;
		}
	}
	else {
		out << mf.getNumerator() << "/" << mf.getDenominator();
	}
	return out;
}
