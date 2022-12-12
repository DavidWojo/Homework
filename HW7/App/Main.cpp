#include <iostream>
#include "Functions.h"
#include "Person.h"
#include "Employee.h"


int main(int argc, char* argv[])
{
	std::cout << "Starting main()..." << std::endl;
	Employee e("David", "Wojciechowski", "111-22-3456", "J51776");
	e.Print();
	Person p("Sylvia", "Kedzierski", "333-22-4567");
	p.Print();

	func1();
	return 0;
}