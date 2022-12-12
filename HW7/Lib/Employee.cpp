#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee(const std::string &fName, const std::string &lName,
	               const std::string &ssNum, const std::string &empID) :
	Person(fName, lName, ssNum),
	employeeID(empID)
{
}

std::string Employee::GetFirstName() const
{
	return Person::GetFirstName();
}

std::string Employee::GetLastName() const
{
	return Person::GetLastName();
}

std::string Employee::GetSocialSecurityNumber() const
{
	return Person::GetSocialSecurityNumber();
}

std::string Employee::GetEmployeeID() const
{
	return this->employeeID;
}

void Employee::Print() const
{
	Person::Print();
	cout << "Employee ID: " << GetEmployeeID() << endl;
}

