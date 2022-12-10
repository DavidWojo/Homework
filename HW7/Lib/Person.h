#pragma once
#include <string>


class Person
{
public:
	Person(const std::string& fname,
		const std::string& lName,
		const std::string& ssNum);
	std::string GetFirstName() const ;
	std::string GetLastName() const ;
	std::string GetSocialSecurityNumber() const ;
	void SetFirstName(const std::string& fName);
	void SetLastName(const std::string& fName);
	void SetSocialSecurityNumber(const std::string& fName);



protected:
	std::string firstName;
	std::string lastName;
	std::string socialSecurityNumber;
};
