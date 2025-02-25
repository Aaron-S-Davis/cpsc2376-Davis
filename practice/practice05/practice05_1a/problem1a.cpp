#include <iostream>
#include <vector>
#include <limits>
#include <iterator>
#include <numeric>

//Write a program that takes user input for a list of integers, 
//stores them in a std::vector, and prints them in the same order 
//using iterators.Then, find and print the sum of only the even 
//numbers using an iterator - based loop.

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

	std::vector<int>::iterator it = v.begin();
	std::cout << "Your list (inputted order): ";
	for (auto it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << '\n';

	int sum = 0;
	for (auto it = v.begin(); it != v.end(); it++) {
		if ((*it % 2) == 0) {
			sum += *it;
		}
	}
	std::cout << "Sum of even numbers: " << sum << '\n';

	return 0;
}
