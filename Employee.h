#pragma once
#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:                                  //chose protected to share access to data variables and skip access thru getters 
	string firstName;
	string lastName;
	int employeeID;
	
	

public:
	Employee() : firstName(""), lastName(""), employeeID(0) {}
	Employee(const string& first, const string& last, int ID) : firstName(first), lastName(last), employeeID(ID) {}


	virtual void weeklySalary() = 0;
	virtual void calcHealthCareContributions() = 0;              // virtul void makes these member functions abstact, requiring the defining to be in the derived classes
	virtual void VacationEarned() = 0;
	virtual void displayInfo() = 0;
	

};
