#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee(const std::string &fName, const std::string &lName,
	               const std::string &ssNum, const std::string &empID) :
	Person(fName, lName, ssNum),
	employeeID(empID)
{
}

std::string Employee::GetEmployeeID() const
{
	return this->employeeID;
}

void Employee::SetEmployeeID(const std::string &empID)
{
	this->employeeID = empID;
}


void Employee::Print() const
{
	Person::Print();
	cout << "Employee ID: " << GetEmployeeID() << endl;
}

