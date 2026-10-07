#include <iostream>
#include <string>

using namespace std;


class Employee {
public:
	virtual double calculateSalary() = 0;
};

class FullTimeEmployee : public Employee {
	double salary;

public:

	FullTimeEmployee(double salary) {
		this->salary = salary;
	}

	double calculateSalary() override {
		return salary;
	}


};



class PartTimeEmployee : public Employee {
	double workedhours;
	double ratehour;

public:

	PartTimeEmployee(double workedhours, double ratehour) {

		this->workedhours = workedhours;
		this->ratehour = ratehour;

	}

	double calculateSalary() override {
		return workedhours * ratehour;
	}


};

int main() {

	FullTimeEmployee fullTime(50000);
	PartTimeEmployee partTime(20, 500);

	cout << "Full Time Employee Salary: "
		<< fullTime.calculateSalary() << endl;

	cout << "Part Time Employee Salary: "
		<< partTime.calculateSalary() << endl;


	return 0;
}