#pragma once

#include "Employee.h"

using namespace std;

class Professional : public Employee {
private:
	int salary;
	int annualVacationDays;
	double yearlyHealthCare;
	int paycheck;
public:
	Professional() : Employee("", "", 0), salary(0), annualVacationDays(0) {}                                                                             //deafault and overloaded constructor
	Professional(const string& first, const string& last, int ID, int salary) : Employee(first, last, ID), salary(salary), annualVacationDays(0) {}

	void weeklySalary() override {

		paycheck = salary / 52;                            //calculating weekly paycheck

	}

	void calcHealthCareContributions() override {

		yearlyHealthCare = salary * .1;                          //salaried employees earn 10 cents to the dollar they earn

	}

	void VacationEarned() override {

		if (salary > 100000) {                        //calculating vacations days, higher valued employees get more benefits, therefore more vacation days
			annualVacationDays = 15;
		}
		else {
			annualVacationDays = 10;
		}

	}

	void displayInfo() {                                                         

		cout << "Professional Employee, ID Number: " << employeeID << endl;
		cout << "   Name: " << firstName << " " << lastName << endl;
		cout << "   Salary: $" << salary << endl;
		cout << "   Vacation Days: " << annualVacationDays << endl;
		cout << endl << "Their weekly salary is $" << paycheck << "." << endl << endl;

	}




};