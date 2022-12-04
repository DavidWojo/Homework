#pragma once
#include <string>


class Person
{
public:
	Person(const std::string& fname,
		const std::string& lName,
		const std::string& ssNum);

private:
	bool FirstNameIsValid(const std::string& fName);
	bool LastNameIsValid(const std::string& fName);
	bool SocialSecurityNumberIsValid(const std::string& fName);
	std::string firstName;
	std::string lastName;
	std::string socialSecurityNumber;
};
