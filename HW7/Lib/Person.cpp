#include "Person.h"
#include <iostream>
#include <exception>


Person::Person(const std::string& fname, const std::string& lName, const std::string& ssNum)
{
	if (!FirstNameIsValid(fname) || !LastNameIsValid(lName) || !SocialSecurityNumberIsValid(ssNum))
		throw std::exception("Invalid first name, last name, or social security number!");
}

bool Person::FirstNameIsValid(const std::string& fName)
{
	return true;
}

bool Person::LastNameIsValid(const std::string& fName)
{
	return true;
}
bool Person::SocialSecurityNumberIsValid(const std::string& fName)
{
	return true;
}
