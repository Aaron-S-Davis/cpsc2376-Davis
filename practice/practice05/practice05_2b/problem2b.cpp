#include <iostream>
#include <vector>

//Write a program that finds the largest element in a vector 
//using std::max_element.Then, modify the program to also find 
//and print the smallest element using std::min_element.

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

	int maxInt = *std::max_element(v.begin(), v.end());
	std::cout << "Max value in list: " << maxInt << '\n';

	int minInt = *std::min_element(v.begin(), v.end());
	std::cout << "Min value in list: " << minInt << '\n';

	return 0;
}
