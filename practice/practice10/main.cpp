#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include <string>
#include <sstream>

class Shape {
public:
	virtual double getArea() const = 0;
	virtual ~Shape() { std::cout << "Shape destroyed!\n"; }
};

class Rectangle : public Shape {
public:
	//rectangle constructor
	Rectangle(double w, double h) : width(w), height(h) {}

	double getArea() const override {
		return width * height;
	}
private:
	double width = 0;
	double height = 0;
};

class Circle : public Shape {
public:
	//circle constructor
	Circle(double r) : radius(r) {}

	double getArea() const override {
		return (radius * radius) * 3.14159;
	}
private: 
	double radius = 0;
};

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
	//calls getArea() function for each shape in vector
	for (const auto& shape : shapes) {
		std::cout << "Area: " << shape->getArea() << "\n";
	}
}

int main() {

	std::vector<std::unique_ptr<Shape>> shapes;

	//open file for parsing
	std::ifstream fin("shapes.txt");
	//check that the file is open
	if (!fin) {
		std::cerr << "Failed to open file!\n";
		return 1;
	}

	std::string line;
	//read file line by line
	while (std::getline(fin, line)) {
		std::istringstream stream(line);
		std::string word;
		double d1, d2;
		stream >> word;

		//read line word by word
		if (word == "rectangle") {
			stream >> d1 >> d2;
			//create unique pointer shape rectangle
			std::unique_ptr<Shape> r = std::make_unique<Rectangle>(d1, d2);
			//move rectangle to new spot in the vector
			shapes.push_back(std::move(r));
		}
		else if (word == "circle") {
			stream >> d1;
			std::unique_ptr<Shape> c = std::make_unique<Circle>(d1);
			shapes.push_back(std::move(c));
		}
	}
	fin.close();

	printAllAreas(shapes);

	return 0;
}