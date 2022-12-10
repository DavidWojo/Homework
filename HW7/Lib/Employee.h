#pragma once
#include "Person.h"
#include <string>

class Employee : Person
{
public:
	Employee(const std::string &fName, const std::string &lName,
		     const std::string &ssNum, const std::string &empID);

	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetSocialSecurityNumber() const;
	std::string GetEmployeeID() const;


protected:
	std::string employeeID;

};
