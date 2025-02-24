#include <iostream>
#include <string>
#include <deque>

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

void addText(std::deque<std::string>& textList, const std::string& input) {
	textList.push_back(input);
	std::cout << '\n';
}

void undoEdit(std::deque<std::string>& textList) {
	textList.pop_back();
	std::cout << "Element removed.\n";
}

void showText(const std::deque<std::string>& textList) {
	int count = 1;
	for (auto text : textList) {
		std::cout << count << ". " << text << '\n';
		count++;
	}
	std::cout << '\n';
}

int main() {

	std::deque<std::string> textList;

	while (true) {
		std::cout << "1. Add text\n2. Undo last edit\n3. Show content\n0. Exit\n";
		int choice = getInt("Choice: ");
		switch (choice) {
		case 1: 
			addText(textList, getString("Text: "));
			break;
		case 2:
			undoEdit(textList);
			break;
		case 3:
			showText(textList);
			break;
		case 0:
			std::cout << "Exiting...\n";
			return 0;
		default:
			std::cout << "Invalid choice\n";
			break;
		}
	}

	return 0;
}
