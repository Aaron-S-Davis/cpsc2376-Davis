#include <iostream>
#include <vector>
#include <numeric>

//Write a program that calculates the sum of all elements in a 
//vector using std::accumulate.Extend the program to also calculate 
//the product of all elements in the vector and print both results.

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

	int sum = std::accumulate(v.begin(), v.end(), 0);
	std::cout << "Sum of integers: " << sum << '\n';

	int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
	std::cout << "Product of integers: " << product << '\n';

	return 0;
}
