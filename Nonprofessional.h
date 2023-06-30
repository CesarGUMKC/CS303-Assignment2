#pragma
#include "Employee.h"

using namespace std;

class Nonprofessional : public Employee {
private:
	int rate;                                     
	double vacationDays;
	int weeklyHours;
	double yearlyHealthCare;
	int paycheck;

public:
	Nonprofessional() : Employee("", "", 0), rate(0), vacationDays(0), weeklyHours(0) {}                                                         //default constructor and overloaded constructor
	Nonprofessional(const string& first, const string& last, int ID, int rate, int hours) : Employee(first, last, ID), rate(rate), weeklyHours(hours), vacationDays(0) {}

	void weeklySalary() override {
		
		paycheck = rate * weeklyHours;                           // calculating weekly paycheck 

	}

	void calcHealthCareContributions() override {
	
		yearlyHealthCare = ((rate * weeklyHours) * 52) * 0.05;	                             //calculating health care contributations, they contribute 5 cents to the dollar they earn

	}

	void  VacationEarned() override {
		
		vacationDays = (weeklyHours * 52 * 0.09) / 24;                    //calculating vacation days, they earn .12 an hour of vacation for every hour they work

	}

	void displayInfo() {                                                      //outputing info
		
		cout << "Employee, ID Number: " << employeeID << endl;
		cout << "   Name: " << firstName << " " << lastName << endl;
		cout << "   Wage: $" << rate << endl;
		cout << "   Vacation Days: " << vacationDays << endl;
		cout << endl << "Their weekly salary is $" << paycheck << "." << endl << endl;
	
	}
	



};