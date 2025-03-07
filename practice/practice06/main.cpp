#include <limits>
#include "Fraction.h"
#include "MixedFraction.h"

int getInt(std::string prompt) {
	int input;
	while (true) {
		std::cout << prompt;
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Error: Must input a valid integer! Please try again.\n";
		}
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return input;
		}
	}
}

Fraction setFraction() {
	Fraction f;
	f.setNumerator(getInt("Input Numerator: "));

	while (true) {
		try {
			f.setDenominator(getInt("Input Denominator(not 0): "));
			break;
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << "\n";
		}
		
	}

	return f;
}

int main() {

	Fraction f1;
	Fraction f2;
	Fraction f3;
	MixedFraction mf1;

	while (true) {
		std::cout << "\nOptions:\n1. Enter a fraction manually\n2. Add a fraction\n3. Subtract a fraction\n4. Multiply by a fraction"
			<< "\n5. Divide by a fraction\n6. Display as a mixed fraction\n7. Clear fraction\n8. Exit\n";
		int choice = getInt("Choice: ");
		switch (choice) {
		case 1:
			f1.setNumerator(getInt("Input Numerator: "));
			while (true) {
				try {
					f1.setDenominator(getInt("Input Denominator(not 0): "));
					break;
				}
				catch (const std::exception& e) {
					std::cerr << "Error: " << e.what() << "\n";
				}
			}
			break;
		case 2:
			f3 = f1 + setFraction();
			std::cout << "Your new fraction: " << f3 << "\n";
			f1 = f3;
			break;
		case 3:
			f3 = f1 - setFraction();
			std::cout << "Your new fraction: " << f3 << "\n";
			f1 = f3;
			break;
		case 4: 
			f3 = f1 * setFraction();
			std::cout << "Your new fraction: " << f3 << "\n";
			f1 = f3;
			break;
		case 5:
			while (true) {
				try {
					f3 = f1 / setFraction();
					break;
				}
				catch (const std::exception& e) {
					std::cerr << "Error: " << e.what() << "\n";
				}

			}
			std::cout << "Your new fraction: " << f3 << "\n";
			f1 = f3;
			break;
		case 6:
			mf1 = f1;
			std::cout << "\n" << mf1 << "\n";
			break;
		case 7:
			f1.setNumerator(0);
			f1.setDenominator(1);
			break;
		case 8:
			return 0;
		default:
			std::cout << "Invalid choice!\n";
			break;
		}
	}

	return 0;
}