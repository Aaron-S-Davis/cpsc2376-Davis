#include <iostream>
#include <list>
#include <string>
#include <limits>

int getInt(std::string prompt) {
	int input;
	std::cout << prompt;
	std::cin >> input;
	while (std::cin.fail()) {
		std::cout << "Invalid input! Try again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> input;
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
		std::getline(std::cin, input);
	}
	return input;
}

void addTask(std::list<std::string>& taskList, std::string input) {
	taskList.push_back(input);
}

void removeTask(std::list<std::string>& taskList, const int& input) {
	std::list<std::string>::iterator it = taskList.begin();
	int count = 1;
	for (auto it = taskList.begin(); it != taskList.end(); it++) {
		if (count == input) {
			taskList.erase(it);
			std::cout << "Task removed\n\n";
			return;
		}
		count++;
	}
	std::cout << "No task found at that index!\n\n";
}

void showTask(const std::list<std::string>& taskList) {
	int count = 1;
	for (std::string task : taskList) {
		std::cout << count << ". " << task << '\n';
		count++;
	}
	std::cout << '\n';
}

int main() {

	std::list<std::string> taskList;

	while (true) {
		std::cout << "1. Add task\n2. Remove task\n3. Show tasks\n0. Exit\n";
		switch (getInt("Choice: ")) {
		case 1: 
			addTask(taskList, getString("Task: "));
			break;
		case 2:
			removeTask(taskList, getInt("Task Index: "));
			break;
		case 3:
			showTask(taskList);
			break;
		case 0:
			return 0;
		}
	}

	return 0;
}
