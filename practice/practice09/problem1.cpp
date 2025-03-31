#include <iostream>
#include <limits>
#include <string>
#include <cctype>

float getFloat(std::string prompt);
std::string getString(std::string prompt);
bool compareStrings(const std::string& str1, const std::string& str2);

int main() {

	float redPotion{ 0.0f };
	float bluePotion{ 0.0f };
	float* flask{ nullptr };

	while (true) {
		std::string input = getString("Choose a potion to add liquid to ('Red' or 'Blue') (type 'Done' if done): ");
		if (compareStrings(input, "red")) {
			flask = &redPotion;
			*flask = +getFloat("Input milliliters of liquid to add to red potion: ");
			flask = nullptr;
		}
		else if (compareStrings(input, "blue")) {
			flask = &bluePotion;
			*flask = +getFloat("Input milliliters of liquid to add to blue potion: ");
			flask = nullptr;
		}
		else if (compareStrings(input, "done")) {
			break;
		}
		else {
			std::cout << "Not a valid response. Try again\n";
		}
		std::cout << "Red potion: " << redPotion << "\n";
		std::cout << "Blue potion: " << bluePotion << "\n";
	}

	return 0;
}

float getFloat(std::string prompt) {
	float input;
	while (true) {
		std::cout << prompt;
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Error: Must input a valid number! Please try again.\n";
		}
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return input;
		}
	}
}

std::string getString(std::string prompt) {
	std::cout << prompt;
	std::string input;
	while (true) {
		std::getline(std::cin, input);
		if (input.empty()) {
			std::cerr << "Error: must input something.\n";
		}
		else {
			return input;
		}
	}
}

bool compareStrings(const std::string& str1, const std::string& str2) {
	if (str1.length() != str2.length()) return false;

	for (int i = 0; i < str1.length(); i++) {
		if (tolower(str1[i]) != tolower(str2[i])) return false;
	}

	return true;
}