#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cctype>

class Strategy {
public:
	virtual void execute(std::string& input) = 0;
	virtual ~Strategy() = default;
};

class Plain : public Strategy {
public:
	void execute(std::string& input) override {
		std::cout << "Your word: " << input << "\n";
	}
};

class Reverse : public Strategy {
public:
	void execute(std::string& input) override {
		std::reverse(input.begin(), input.end());
		std::cout << "Your reversed word: " << input << "\n";
	}
};

class Uppercase : public Strategy {
	void execute(std::string& input) override {
		//parse through string by character
		for (char& c : input) {
			//make each character uppercase
			c = std::toupper(static_cast<unsigned char>(c));
		}
		std::cout << "Your uppercased word: " << input << "\n";
	}
};

class NonVowel : public Strategy {
	void execute(std::string& input) override {
		std::string result;
		for (char& c : input) {
			char next = std::tolower(static_cast<unsigned char>(c));
			if (next != 'a' && next != 'e' && next != 'i' && next != 'o' && next != 'u') {
				//build new string from nonvowel letters
				result += c;
			}
		}
		input = result;
		std::cout << "Your nonvowel word: " << input << "\n";
	}
};

class Censored : public Strategy {
	std::vector<std::string> badWords{ "hell", "shit", "bitch", "damn" };

	std::string toLower(const std::string& s) {
		std::string lower = s;
		std::transform(lower.begin(), lower.end(), lower.begin(),
			[](unsigned char c) { return std::tolower(c); });
		return lower;
	}

	std::string censor(const std::string& word) {
		if (word.size() <= 2) return word;
		return word.front() + std::string(word.size() - 2, '*') + word.back();
	}

public:
	void execute(std::string& input) override {
		std::stringstream ss(input);
		std::string word, output;

		while (ss >> word) {
			std::string check = toLower(word);
			if (std::find(badWords.begin(), badWords.end(), check) != badWords.end()) {
				word = censor(word);
			}
			if (!output.empty()) output += " ";
			output += word;
		}

		input = output;
		std::cout << "Your censored word: " << input << "\n";
	}
};

class Printer {
	std::unique_ptr<Strategy> strategy;
public:
	Printer(std::unique_ptr<Strategy> s = std::make_unique<Plain>()) : strategy(std::move(s)) {}

	void setStrategy(std::unique_ptr<Strategy> s) {
		strategy = std::move(s);
	}

	void print(std::string& text) const {
		if (strategy) strategy->execute(text);
	}
};

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

int getInt(const std::string& prompt) {
	int input;
	while (true) {
		std::cout << prompt;
		std::cin >> input;

		if (std::cin.fail()) {
			std::cout << "Invalid input! Try again.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return input;
		}
	}
}

int main() {

	std::string input = getString("Enter a string input: ");

	Printer printer;

	while (true) {
		std::cout << "Choose how you want to manipulate the string.\n";
		std::cout << "Options: \n1. Plain\n2. Reverse\n3. Uppercase\n4. Remove Vowels\n5. Censor bad words\n6. New word\n0. Exit\n";
		switch (getInt("Your choice: ")) {
		case 1:
			printer.setStrategy(std::make_unique<Plain>());
			break;
		case 2:
			printer.setStrategy(std::make_unique<Reverse>());
			break;
		case 3:
			printer.setStrategy(std::make_unique<Uppercase>());
			break;
		case 4:
			printer.setStrategy(std::make_unique<NonVowel>());
			break;
		case 5:
			printer.setStrategy(std::make_unique<Censored>());
			break;
		case 6:
			input = getString("Enter a string input: ");
			continue;
		case 0:
			return 0;
		default:
			std::cout << "Invalid Choice!\n";
			continue;
		}
		printer.print(input);
	}
	

	return 0;
}