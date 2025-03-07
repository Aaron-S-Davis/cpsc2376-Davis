#pragma once

#include "Fraction.h"

class MixedFraction : public Fraction {
public:
	//constructors
	MixedFraction(int whole = 0, int n = 0, int d = 1);
	MixedFraction(const Fraction& fraction);

	//extra function
	friend std::ostream& operator<<(std::ostream& out, const MixedFraction& mf);
private:
	int whole;
};
