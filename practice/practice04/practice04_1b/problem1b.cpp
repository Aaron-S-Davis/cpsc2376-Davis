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

void greet(std::string name = "Guest", std::string prefix = "Hello") {
	std::cout << prefix << " " << name << '\n';
}

int main() {
	while (true) {
		std::cout << "1. Default greeting\n2. Greet by name\n3. Custom greeting\n0. Exit\n";
		int choice = getInt("Choose an option: ");
		switch (choice) {
		case 0:
			return 0;
		case 1:
			greet();
			break;
		case 2:
			greet(getString("Enter name: "));
			break;
		case 3:
			greet(getString("Enter name: "), getString("Enter greeting prefix: "));
			break;
		default:
			std::cout << "Error. Not a valid choice\n";
			break;
		}
	}

	return 0;
}
