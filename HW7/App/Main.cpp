#include <iostream>
#include "Functions.h"
#include "Person.h"
#include "Employee.h"
#include <vector>
#include <typeinfo>

/* 
* This aplication is used to demonstrate C++ poymorphism via virtual functions.
* We have a Person base class and a derived class called Employee.  That means Employee
* inherits from Person.  We have a pointer to a Person object and a pointer to an 
* Employee object.  We then call the appropriate Print() method, depending on wether
* the object being pointed to is a base class object or a derived class object.
*/


/*
* Given a reference to a const Person object, call the Print()
* method (which is virtual). Also print the type of object that
* we are dealing with.
*/
void PrintPeopleInfo_ViaReference(const Person &pRef)
{
	std::string s = "Object Type: " + std::string(typeid(pRef).name());
	std::cout << s << std::endl;
	pRef.Print();
	std::cout << std::endl;
}

/*
* Given a pointer to a const Person object, call the Print()
* method (which is virtual). Also print the type of object that 
* we are dealing with.
*/
void PrintPeopleInfo_ViaPointer(const Person *const pPtr)
{
	std::string s = "Object Type: " + std::string(typeid(*pPtr).name());
	std::cout << s << std::endl;
	pPtr->Print();
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	std::cout << "Starting main()..." << std::endl;

	// A vector to hold 2 items (pointers to base class objects)
	std::vector<Person *> peopleVec(2);

	// create an Employee object, then change the attributes
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