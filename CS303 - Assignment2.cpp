#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Employee.h"
#include "Nonprofessional.h"
#include "Professional.h"

using namespace std;

int main()
{
	Professional teacher("Jawad", "Hussain", 42069, 300000);                            //instance of Professional derived class

	teacher.calcHealthCareContributions();
	teacher.VacationEarned();
	teacher.weeklySalary();
	teacher.displayInfo();


	Nonprofessional student("Cesar", "Giner", 1010101, 22.25, 30);                             //instance of Nonprofessional class
	  
	student.calcHealthCareContributions();
	student.VacationEarned();
	student.weeklySalary();
	student.displayInfo();

}

