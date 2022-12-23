#include <iostream>
#include "Functions.h"
#include "Person.h"
#include "Employee.h"
#include <vector>
#include <typeinfo>


/*
* Given a reference to a const Person object, call the Print()
* method (which is virtual). Also print the type of object that
* we are dealing with.
*/
void PrintPeopleInfo_ViaReference(const Person &personRef)
{
	std::string s = "Object Type: " + std::string(typeid(personRef).name());
	std::cout << s << std::endl;
	personRef.Print();
	std::cout << std::endl;
}

/*
* Given a pointer to a const Person object, call the Print()
* method (which is virtual). Also print the type of object that 
* we are dealing with.
*/
void PrintPeopleInfo_ViaPointer(const Person *const personPtr)
{
	std::string s = "Object Type: " + std::string(typeid(*personPtr).name());
	std::cout << s << std::endl;
	personPtr->Print();
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	std::cout << "Starting main()..." << std::endl;

	// A vector to hold 2 items (pointers to Person objects)
	std::vector<Person *> peopleVec(2);

	// create an Employee object
	Employee employee("N/A", "N/A", "N/A", "N/A");
	employee.SetFirstName("David ");
	employee.SetLastName("Wojo");
	employee.SetSocialSecurityNumber("111-22-3333");
	employee.SetEmployeeID("J54321");

	// create a Person object
	Person person("Joe", "Smith", "333-22-4567");

	peopleVec[0] = &employee;
	peopleVec[1] = &person;

	for (Person *p : peopleVec)
		PrintPeopleInfo_ViaPointer(p);

	std::cout << std::endl;
	std::cout << std::endl;

	for (Person *p : peopleVec)
		PrintPeopleInfo_ViaReference(*p);

	func1();
	return 0;
}