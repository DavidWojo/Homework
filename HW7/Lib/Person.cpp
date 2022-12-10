#include "Person.h"
#include <iostream>
#include <exception>


Person::Person(const std::string& fName, const std::string& lName, const std::string& ssNum)
{
	this->SetFirstName(fName);
	this->SetLastName(lName);
	this->SetSocialSecurityNumber(ssNum);
}

std::string Person::GetFirstName() const
{
    return this->firstName;
}


std::string Person::GetLastName() const
{
	return this->lastName;
}

std::string Person::GetSocialSecurityNumber() const
{
	return this->socialSecurityNumber;
}

void Person::SetFirstName(const std::string& fName)
{
	if (fName.empty())
		throw std::exception("Invalid first name!");
	this->firstName = fName;
}

void Person::SetLastName(const std::string& lName)
{
	if (lName.empty())
		throw std::exception("Invalid last name!");
	this->lastName = lName;
}

void Person::SetSocialSecurityNumber(const std::string& ssNum)
{
	if (ssNum.empty())
		throw std::exception("Invalid social security number!");
	this->socialSecurityNumber = ssNum;
}
