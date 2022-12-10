#include "Employee.h"


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


