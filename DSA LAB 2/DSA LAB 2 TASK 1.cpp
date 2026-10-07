#include <iostream>
#include <string>

using namespace std;

class Shape {
public:
	virtual double area() = 0 {

	}






};
class Circle :public Shape {
	double radious;
public:
	 Circle (double r) {
		radious = r;
	}

	double area() override {
		return 3.24 * radious * radious;

	}



};


class  Rectangle : public Shape {
	double length;
	double width;
public:
	Rectangle(double l, double w) {

		length = l;
		width = w;

	}

	double area() override {

		return length * width;
	}

};


int main() {

	
	Circle c(5);
	Rectangle r(4, 6);

	cout << "Circle Area: " << c.area() << endl;
	cout << "Rectangle Area: " << r.area() << endl;





	return 0;
}