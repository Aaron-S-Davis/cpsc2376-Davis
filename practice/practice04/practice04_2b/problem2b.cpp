#include <iostream>
#include <string>
#include <limits>

int getInt(std::string prompt) {
	std::cout << prompt;
	int input;
	std::cin >> input;
	while (std::cin.fail()) {
		std::cout << "Invalid input! Try again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return input;
}

std::string getString(std::string prompt) {
	std::cout << prompt;
	std::string input;
	std::getline(std::cin, input);
	while (std::cin.fail()) {
		std::cout << "Invalid input! Try again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return input;
}

template <typename T>
T findMax(T a, T b, T c) {
	if (a > b && a > c) {
		return a;
	}
	else if (b > a && b > c) {
		return b;
	}
	else if (c > a && c > b) {
		return c;
	}
	else {
		std::cout << "Error. No max value\n";
		return a;
	}
}

int main() {

	while (true) {
		std::cout << "Compare (1) Numbers or (2) strings or (0) Exit? ";
		int choice = getInt("");
		int maxInt;
		std::string maxString;
		switch (choice) {
		case 1:
			maxInt = findMax(getInt("Enter third value: "), getInt("Enter second value: "), getInt("Enter first value: "));
			std::cout << "Max value: " << maxInt << '\n';
			break;
		case 2:
			maxString = findMax(getString("Enter third value: "), getString("Enter second value: "), getString("Enter first value: "));
			std::cout << "Max value: " << maxString << '\n';
			break;
		case 0:
			std::cout << "Exiting...";
			return 0;
		default:
			std::cout << "Error. Invalid choice!\n";
			break;
		}
	}

	return 0;
}
