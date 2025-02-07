#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void fileStartup(const std::string& filename, double& balance);
void checkBalance(const std::string& filename, double& balance);
void deposit(const std::string& filename, double& balance);
void withdraw(const std::string& filename, double& balance);
void readBalanceFromFile(const std::string& filename, double& balance);
void writeBalanceToFile(const std::string& filename, double input);
int getInt();
double getDouble();

int main() {
	
	double balance; //global variable to serve as an argument for functions
	fileStartup("account_balance.txt", balance);

	while (true) { //simple menu ui
		std::cout << "1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n4. Exit\n\nEnter your choice: ";
		int choice = getInt();
		if (choice == 1) {
			checkBalance("account_balance.txt", balance);
		}
		else if (choice == 2) {
			deposit("account_balance.txt", balance);
		}
		else if (choice == 3) {
			withdraw("account_balance.txt", balance);
		}
		else if (choice == 4) {
			break;
		}
		else {
			std::cout << "Error: Must enter valid input\n";
		}
	}
	return 0;
}

void fileStartup(const std::string& filename, double& balance) {
	std::ifstream inFile(filename); //attempt to open txt file
	if (inFile) { //if file is opened successfully
		inFile.close(); //close file since it is reopened in read function
		readBalanceFromFile(filename, balance);
		std::cout << "Welcome to your bank account!\nYour current balance is: $" << std::fixed << std::setprecision(2) << balance << "\n\n";
	}
	else { //if the file is not open
		inFile.close();
		double input{ 100.00 }; //gives input variable value of $100
		writeBalanceToFile(filename, input); //writes $100 to file as a default to starting bank account
		std::cout << "Welcome to your bank account!\nInitializing your balance to: $" << std::fixed << std::setprecision(2) << input << "\n\n";
	}
}

void checkBalance(const std::string& filename, double& balance) {
	readBalanceFromFile(filename, balance);
	std::cout << "\nCurrent balance: $" << std::fixed << std::setprecision(2) << balance << "\n\n";
}

void deposit(const std::string& filename, double& balance) {
	readBalanceFromFile(filename, balance);
	std::cout << "Deposit amount: ";
	double input = getDouble();
	
	while (input < 0) { //checks that deposit amount is not a negative number
		std::cout << "Error: Deposit amount must be positive\nDeposit amount: ";
		input = getDouble();
	}

	balance += input; //adds inputted amount to user balance
	writeBalanceToFile(filename, balance);
}

void withdraw(const std::string& filename, double& balance) {
	readBalanceFromFile(filename, balance);
	std::cout << "Withdrawal amount: ";
	double input = getDouble();

	while (input < 0 || input > balance) { //checks that withdrawal amount is not negative and doesn't exceed how much money the user has
		if (input < 0) { 
			std::cout << "Error: Withdrawal amount must be a positive number\nWithdrawal amount: ";
		}
		else {
			std::cout << "Error: Insufficient funds. Your current balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
			std::cout << "Withdrawal amount: ";
		}
		input = getDouble();
	}

	balance -= input;
	writeBalanceToFile(filename, balance);
}

void readBalanceFromFile(const std::string& filename, double& balance) {
	std::ifstream inFile(filename);
	inFile >> balance;
	inFile.close();
}

void writeBalanceToFile(const std::string& filename, double balance) {
	std::ofstream outFile(filename);
	outFile << balance;
	outFile.close();
}

int getInt() { //validates double value the same as getDouble()
	int input;
	bool validInput = false; //variable for checking if while loop can be exited

	while (!validInput) {
		std::cin >> input;
		if (std::cin.fail()) {
			std::cout << "Error: expected integer value\nPlease enter an integer: ";
			std::cin.clear(); //clears the error on std::cin so a new value can be input
			std::cin.ignore();//ignore the remaining input
		}
		else {
			validInput = true;
		}
	}
	return input;
}

double getDouble() { 
	double input;
	bool validInput = false; 

	while (!validInput) {
		std::cin >> input;
		if (std::cin.fail()) {
			std::cout << "Error: expected integer value\nPlease enter an integer: ";
			std::cin.clear();
			std::cin.ignore(); 
		}
		else {
			validInput = true;
		}
	}
	return input;
}
