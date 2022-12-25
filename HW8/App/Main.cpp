#include <iostream>
#include <memory>

using namespace std;

/*
 * The purpose of this app is demonstrate the use of the unique_ptr class.

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
	cout << "Constructor for Integer " << value << endl;
}

Integer::~Integer()
{
	cout << "Destructor for Intger " << value << endl;
}

void Integer::SetInteger(int i)
{
	value = i;
}

int Integer::GetInteger() const
{
	return value;
}



int main(int argc, char* argv[])
{
	unique_ptr<Integer> pInt(new Integer(34));
	return 0;
}