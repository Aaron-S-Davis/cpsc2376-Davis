#include <iostream>
#include <limits>

//convertTemperature(double temp, char scale = 'F')
//'F': Converts Celsius to Fahrenheit
//'C' : Converts Fahrenheit to Celsius
//The UI offers both options, but both call the same function.

void convertTemperature(double temp, char scale = 'F') {
	if (scale == 'F') {
		std::cout << "Converted: " << (temp * 1.8) + 32 << scale << "\n";
	}
	else if (scale == 'C') {
		std::cout << "Converted: " << (temp - 32) * (5 / 9) << scale << "\n";
	}
	else {
		std::cout << "Error\n";
	}
}

int getChoice() {
	std::cout << "Choose an option: ";
	int choice;
	std::cin >> choice;
	while (std::cin.fail()) {
		std::cout << "Error: Please enter valid input: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> choice;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return choice;
}

double getTemp() {
	std::cout << "Enter temperature: ";
	double temp;
	std::cin >> temp;
	while (std::cin.fail()) {
		std::cout << "Error: Please enter valid input: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> temp;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return temp;
}

int main() {

	while(true) {
		std::cout << "1. Convert Celsius to Fahrenheit\n2. Convert Fahrenheit to Celsius\n0. Exit\n";
		int choice = getChoice();
		if (choice == 1) {
			convertTemperature(getTemp(), 'F');
		}
		else if (choice == 2) {
			convertTemperature(getTemp(), 'C');
		}
		else if (choice == 0) {
			break;
		}
		else {
			std::cout << "Error: Must choose 1 or 2\n";
		}
	}

	return 0;
}
