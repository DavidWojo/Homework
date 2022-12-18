#pragma once
#include <string>
#include "Person.h"

class Employee : public Person
{
public:
	Employee(const std::string &fName, const std::string &lName,
		     const std::string &ssNum, const std::string &empID);

	std::string GetEmployeeID() const;
	void SetEmployeeID(const std::string &empID);
	virtual void Print() const override;

private:
	std::string employeeID;

};
