#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Employee {
private:
	std::string name;
	int id;
public:
	//constructor
	Employee(std::string n, int i)
		:name{ n }
		, id{ i }
	{
	}

	//virtual functions
	virtual double calculateSalary() const = 0;
	virtual void displayInfo() const { std::cout << "ID: " << id << ", Name: " << name; }
	virtual ~Employee() {}
};

class SalariedEmployee : public Employee {
private:
	double monthlySalary;
public:
	//constructor
	SalariedEmployee(std::string name, int id, double salary)
		: Employee{ name, id }
		, monthlySalary{ salary }
	{
	}

	//functions
	double calculateSalary() const override { return monthlySalary; }
	void displayInfo() const override {
		Employee::displayInfo();
		std::cout << ", Salary: " << monthlySalary << "\n";
	}
};

class HourlyEmployee : public Employee {
private:
	double hourlyRate;
	int hoursWorked;
public:
	//constructor
	HourlyEmployee(std::string name, int id, double rate, int hours)
		: Employee{ name, id }
		, hourlyRate{ rate }
		, hoursWorked{ hours }
	{
	}

	//functions
	double calculateSalary() const override { return hourlyRate * hoursWorked; }
	void displayInfo() const override {
		Employee::displayInfo();
		std::cout << ", Type: Hourly, Hours Worked: " << hoursWorked << ", Hourly Rate: " << hourlyRate << ", Salary: " << calculateSalary() << "\n";
	}
};

class CommissionEmployee : public Employee {
private:
	double baseSalary;
	double salesAmount;
	double commissionRate;
public:
	//constructor
	CommissionEmployee(std::string name, int id, double salary, double sales, double commission)
		: Employee{ name, id }
		, baseSalary{ salary }
		, salesAmount{ sales }
		, commissionRate{ commission }
	{
	}

	//functions
	double calculateSalary() const override { return baseSalary + (salesAmount * commissionRate); }
	void displayInfo() const override {
		Employee::displayInfo();
		std::cout << ", Type: Commission, Base Salary: " << baseSalary << ", Sales: " << salesAmount << ", Commission Rate: " << commissionRate << ", Salary: " << calculateSalary() << "\n";
	}
};

int main() {

	std::vector<Employee*> employees;

	std::ifstream fin("employees.txt");
	std::string line;
	if (!fin.is_open()) {
		std::cout << "Unable to open file\n";
		return 0;
	}
	while (getline(fin, line)) {
		std::string type, name;
		int id;
		if (line.find("Salaried", 0) != std::string::npos) {
			std::stringstream ss(line);
			double sal{ 0 };
			ss >> type >> id >> name >> sal;
			employees.push_back(new SalariedEmployee(name, id, sal));
		}
		if (line.find("Hourly") != std::string::npos) {
			std::stringstream ss(line);
			double rate{ 0 }, hours{ 0 };
			ss >> type >> id >> name >> rate >> hours;
			employees.push_back(new HourlyEmployee(name, id, rate, hours));
		}
		if (line.find("Commission") != std::string::npos) {
			std::stringstream ss(line);
			double sal{ 0 }, sales{ 0 }, com{ 0 };
			ss >> type >> id >> name >> sal >> sales >> com;
			employees.push_back(new CommissionEmployee(name, id, sal, sales, com));
		}
	}
	fin.close();

	for (Employee* e : employees) {
		e->displayInfo();
	}

	for (Employee* e : employees) {
		delete e;
	}

	return 0;
}
