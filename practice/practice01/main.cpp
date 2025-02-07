#include <iostream>
#include <vector>

void addToVector(std::vector<int>& nums) {//pass by reference so the original vector is changed
	int value;
	std::cout << "Input an integer: ";
	std::cin >> value;
	nums.push_back(value);//push_back for a simple way to add an element to the vector
}

void printVector(const std::vector<int>& nums) {//pass by const reference since the vector only needs to be read and doesn't need to be modified
	for (auto num : nums) std::cout << num << ", ";
}

void doubleVector(std::vector<int>& nums) {
	for (int i{ 0 }; i < nums.size(); i++) {
		nums.at(i) *= 2;
	}
}

void printSum(const std::vector<int>& nums) {
	int sum{ 0 };
	for (int i{ 0 }; i < nums.size(); i++) {//iterates through vector and adds each value to the total sum
		sum += nums.at(i);
	}
	std::cout << "Sum of all numbers in the vector: " << sum;
}

void printMultiples(const std::vector<int>& nums) {
	int value, check{ 0 };
	std::cout << "Input a value: ";
	std::cin >> value;
	for (int i{ 0 }; i < nums.size(); i++) {
		if (nums.at(i) % value == 0) {//if the remainder is zero, the value is a multiple
			std::cout << nums.at(i) << ", ";
			check++;//to check that at least one value is found, otherwise the user will be notified that one wasn't
		}
	}
	if (check < 1) {
		std::cout << "No applicable values found!";
	}
}

int main() {

	std::vector<int> nums;

	while (true) {//simple menu ui
		int choice;
		std::cout << "\n1. Add to vector\n2. Print vector\n3. Double vector\n4. Calculate the sum\n5. Print multiples of user-defined value\n0. Exit\n";
		std::cin >> choice;
		if (choice == 0) {
			break;
		}
		else if (choice == 1) {
			addToVector(nums);//calls and runs appropriate function
		}
		else if (choice == 2) {
			printVector(nums);
		}
		else if (choice == 3) {
			doubleVector(nums);
		}
		else if (choice == 4) {
			printSum(nums);
		}
		else if (choice == 5) {
			printMultiples(nums);
		}
		else {
			std::cout << "INVALID INPUT. TRY AGAIN.";
		}
	}

	return 0;
}