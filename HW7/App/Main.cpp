#include <iostream>
#include "Functions.h"
#include "Person.h"
#include "Employee.h"
#include <vector>


void PrintPeopleInfo_ViaReference(const Person & personRef)
{
		personRef.Print();
		std::cout << std::endl;
}

void PrintPeopleInfo_ViaPointer(const Person *personPtr)
{
		personPtr->Print();
		std::cout << std::endl;
}


int main(int argc, char* argv[])
{
	std::cout << "Starting main()..." << std::endl;

	std::vector<const Person *> peopleVec(2);
	Employee employee("N/A", "N/A", "N/A", "N/A");
	employee.SetFirstName("David ");
	employee.SetLastName("Wojciechowski");
	employee.SetSocialSecurityNumber("111-22-3333");
	employee.SetEmployeeID("J51776");

	Person person("Joe", "Smith", "333-22-4567");

	peopleVec[0] = &employee;
	peopleVec[1] = &person;

	for (const Person* p : peopleVec)
		PrintPeopleInfo_ViaPointer(p);

	std::cout << std::endl;
	std::cout << std::endl;

	for (const Person* p : peopleVec)
		PrintPeopleInfo_ViaReference(*p);

	func1();
	return 0;
}