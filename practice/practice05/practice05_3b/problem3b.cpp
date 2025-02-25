#include <iostream>
#include <vector>
#include <algorithm>

//Write a program that prompts the user for a list of integers 
//and a threshold value.Use std::count_if with a lambda function 
//to count how many elements are greater than the threshold.
//Modify the program to use std::remove_if with a lambda to filter 
//out values below the threshold and print the modified list.

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

	//identifies elements that are below threshold
	int threshold = 10;
	auto aboveThreshold = [threshold](int a) { return a > threshold; };
	int count = std::count_if(v.begin(), v.end(), aboveThreshold);
	std::cout << "Number of elements above 10: " << count << '\n';

	//remove elements that are below threshold
	auto belowThreshold = [threshold](int a) { return a < threshold; };
	v.erase(std::remove_if(v.begin(), v.end(), belowThreshold), v.end());
	std::cout << "Elements below threshold removed.\n";
	
	for (auto it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << '\n';

	return 0;
}
