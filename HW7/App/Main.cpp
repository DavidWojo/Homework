#include <iostream>
#include "Functions.h"
#include "Person.h"
#include "Employee.h"


int main(int argc, char* argv[])
{
	std::cout << "Starting main()..." << std::endl;
	Person* people[5];

	Employee employee("David", "Wojciechowski", "111-22-3456", "J51776");
	employee.SetFirstName("AA");
	employee.SetLastName("bb");
	employee.SetSocialSecurityNumber("11");

	Person person("Sylvia", "Kedzierski", "333-22-4567");

	people[0] = (Person*)&employee;
	people[1] = (Person*)&person;

	for (int i = 0; i < 2; i++)
	{
		Person* personPtr = people[i];

		personPtr->Print();
		std::cout << std::endl;
	}
	func1();
	return 0;
}