#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

//Write a program that prompts the user to enter a list 
//of integers.Use std::for_each with a lambda function 
//to print each element squared.Then, use a new lambda 
//to help sum up all squared values using accumulate and 
//print the result.

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

	//lambda for squared values
	std::cout << "Your element(s) squared: ";
	auto printSquares = [](const int& a) { std::cout << a * a << " "; };
	std::for_each(v.begin(), v.end(), printSquares);
	std::cout << '\n';

	//accumulate for sum of squared values
	auto sumOfSquares = [](const int& sum, const int& value) { return sum + value * value; };
	int sum = std::accumulate(v.begin(), v.end(), 0, sumOfSquares);
	std::cout << "Sum of squared values: " << sum << '\n';

	return 0;
}
