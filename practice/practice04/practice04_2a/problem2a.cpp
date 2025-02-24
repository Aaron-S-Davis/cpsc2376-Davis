#include <iostream>
#include <limits>
#include <iomanip>

template<typename t>
t calculate(t x, t y, char op) {
	if (op == '+') {
		return x + y;
	}
	else if (op == '-') {
		return x - y;
	}
	else if (op == '*') {
		return x * y;
	}
	else if (op == '/') {
		if (y == 0) {
			std::cout << "error. division by zero\n";
			return nan("");
		}
		else {
			return x / y;
		}
	}
	else {
		std::cout << "error. invalid operator\n";
		return nan("");
	}
}

template<typename t>
t getinput() {
	t input;
	std::cin >> input;
	while (std::cin.fail()) {
		std::cout << "error: invalid input. try again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> input;
	}
	return input;
}

char getoperation() {
	char op;
	std::cin >> op;
	while (std::cin.fail() || (op != '+' && op != '-' && op != '*' && op != '/')) {
		std::cout << "error: invalid input. try again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> op;
	}
	return op;
}

int main() {

	while (true) {
		char op;
		std::cout << "Enter first number: ";
		double x = getinput<double>();
		std::cout << "Enter second number: ";
		double y = getinput<double>();
		if (x == static_cast<int>(x) && y == static_cast<int>(y)) {
			int intx = static_cast<int>(x);
			int inty = static_cast<int>(y);
			std::cout << "choose operation (+, -, *, /): ";
			op = getoperation();
			std::cout << "result: " << calculate(intx, inty, op) << '\n';
		}
		else {
			std::cout << "choose operation (+, -, *, /): ";
			op = getoperation();
			std::cout << "result: " << calculate(x, y, op) << '\n';
		}
	}

	return 0;
}