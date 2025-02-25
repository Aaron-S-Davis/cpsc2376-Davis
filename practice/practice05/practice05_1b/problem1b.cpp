#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

//Write a program that takes user input for a list of 
//integers, stores them in a std::vector, and prints 
//them in reverse order using iterators.

int getInt(std::string prompt) {
	std::cout << prompt;
	int input;
	std::cin >> input;
	while (std::cin.fail()) {
		std::cout << "Error. Invalid input. Try again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> input;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return input;
}

int main() {

	std::vector<int> v;

	while (true) {
		std::cout << "\n1. Add a number to vector\n0. Continue\n";
		int choice = getInt("Choice: ");
		if (choice == 1) {
			v.push_back(getInt("Enter an integer: "));
		}
		else if (choice == 0) {
			break;
		}
		else {
			std::cout << "Invalid choice. Must be 1 or 0!\n";
		}
	}

	std::cout << "Your integers in reverse order: ";
	for (auto it = v.end() - 1; it > v.begin(); it--) {
		std::cout << *it << " ";
	}
	std::cout << '\n';

	return 0;
}
