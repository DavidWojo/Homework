#include <iostream>
#include <memory>
#include <utility>


/*
 * The purpose of this app is demonstrate the use of the unique_ptr class
 * instead of using old-fashioned memory management via keywords 'new'
 * and 'delete'.

*/

class Integer
{
public:
	Integer(int i = 0);
	~Integer();
	void SetInteger(int i);
	int GetInteger() const;
private:
	int value;
};

Integer::Integer(int i) : value(i)
{
	std::cout << "Constructor for integer, value is " << value << std::endl;
}

Integer::~Integer()
{
	std::cout << "Destructor for integer " << value << std::endl;
}

void Integer::SetInteger(int i)
{
	value = i;
}

int Integer::GetInteger() const
{
	return value;
}

std::unique_ptr<Integer> f1()
{
	return std::make_unique<Integer>();
}

int *f2()
{
	int *pInt = new int(0);
	return pInt;
}

int main(int argc, char* argv[])
{
	//int *pIntBad = Bad();
	//cout << "The integer has a value of " << *pIntBad << endl;

	std::unique_ptr<Integer> pInt{};
	std::cout << "pInt is " << (pInt ? "not null" : "null") << std::endl;
	pInt = f1();
	std::cout << "pInt is " << (pInt ? "not null" : "null") << std::endl;
	pInt->SetInteger(77);
	std::cout << "The integer has a value of " << pInt->GetInteger() << std::endl;

	return 0;
}