#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <numeric>

class GradeBook;

class Observer {
public:								
	virtual void update(const GradeBook& gradeBook) = 0;
	virtual ~Observer() = default;
};

class GradeBook {
	std::vector<std::weak_ptr<Observer>> observers;
	std::vector<std::pair<std::string, double>> grades;
public:

	void attach(const std::shared_ptr<Observer>& obs) {
		observers.push_back(obs);
	}

	//getter
	std::vector<std::pair<std::string, double>> getGrades() const {
			return grades;
	}

	//setter
	void setGrade(std::pair<std::string, double> student) {
		grades.push_back(student);
		notify();
	}

	bool updateGrade(const std::string& name, double newGrade) {
		for (auto& s : grades) {
			//sets new grade for inputted name
			if (s.first == name) {
				s.second = newGrade;
				//notify observers
				notify();
				return true;
			}
		}
		return false;
	}

	void removeStudent(const std::string& name) {
		//points it at found name
		auto it = std::remove_if(grades.begin(), grades.end(),
			[&](const auto& s) { return s.first == name; });

		if (it != grades.end()) {
			grades.erase(it, grades.end());
			notify();
			return;
		}
		std::cout << "Student not found\n";
	}

	

private:
	void notify() {
		observers.erase(std::remove_if(observers.begin(), observers.end(),
			[this](std::weak_ptr<Observer>& wp) {
				//checks if subject is still being used
				if (auto sp = wp.lock()) {
					sp->update(*this);
					return false;
				}
				return true;
			}),
			observers.end());
	}
};

class Averager : public Observer {
public: 
	void update(const GradeBook& gradeBook) override {
		auto grades = gradeBook.getGrades();
		if (grades.empty()) {
			std::cout << "No grades available\n";
			return;
		}
		double sum = std::accumulate(grades.begin(), grades.end(), 0.0,
			[](double acc, const auto& pair) {
				return acc + pair.second;
			});
		std::cout << "New average: " << (sum / grades.size()) << "\n";
	}
};

class Notifier : public Observer {
public:
	void update(const GradeBook& gradeBook) override {
		std::cout << "GradeBook has been updated\n";
		for (auto g : gradeBook.getGrades()) {
			if (g.second < 60) {
				std::cout << g.first << "'s grade has fallen below 60%, email sent to " << g.first << "@gmail.com\n";
			}
		}
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

		if (std::cin.fail() || input < 0 || input > 100) {
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
	GradeBook gradeBook;
	auto averager = std::make_shared<Averager>();
	auto notifier = std::make_shared<Notifier>();
	gradeBook.attach(averager);
	gradeBook.attach(notifier);

	while (true) {
		std::cout << "\nOptions:\n1. Add student\n2. Change grade\n3. Remove student\n4. View grades\n0. Exit\n";
		std::string name;
		int grade;

		switch (getInt("Your choice: ")) {
		case 1:
			gradeBook.setGrade({ getString("Enter student name: "), static_cast<double>(getInt("Enter grade (0 to 100): ")) });
			break;
		case 2:
			if (!gradeBook.updateGrade(getString("Enter student name: "), getInt("Enter new grade(0 to 100): "))) {
				std::cout << "Student not found.\n";
			}
			break;
		case 3:
			gradeBook.removeStudent(getString("Enter student name: "));
			break;
		case 4:
			std::cout << "Current Grades:\n";
			for (const auto& student : gradeBook.getGrades()) {
				std::cout << student.first << ": " << student.second << "\n";
			}
			break;
		case 0:
			return 0;
		default:
			std::cout << "Invalid choice!\n";
			break;
		}
	}
}
