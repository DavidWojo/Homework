#include <iostream>
#include <string>


class Resource
{
private:
	std::string name;
public:
	Resource(const std::string n);
	~Resource(void);
	std::string GetName() const { return name; }
};


Resource::Resource(const std::string n) :
	name(n)
{
	std::cout << "constructing " << name << '\n';
}

Resource::~Resource(void)
{
	std::cout << "destructing " << name << '\n';
}

class Person
{
private:
	std::string name;
	int arbitrarynumber;
	Resource* pResource;

public:
	Person(const std::string &n, int arbitrary);
	Person(const Person & p);
	~Person();
	Person& operator=(const Person & p);
	std::string GetName() const;
	int GetNumber() const { return arbitrarynumber; }
	void SetNumber(int number) { arbitrarynumber = number; }
	void SetName(std::string n) { name = n; }
	void AddResource();
	std::string GetResourceName() const { return pResource ? pResource->GetName() : ""; }
};

Person::Person(const std::string &n,	int arbitrary) :
	name(n),
	arbitrarynumber(arbitrary),
	pResource(nullptr)
{
}

Person::Person(const Person & p)
{
	name = p.name;
	arbitrarynumber = p.arbitrarynumber;
	pResource = new Resource(p.GetResourceName());
}

Person::~Person()
{
	delete pResource;
}

Person& Person::operator=(const Person & p)
{
	delete pResource;
	name = p.name;
	arbitrarynumber = p.arbitrarynumber;
	pResource = new Resource(p.pResource->GetName());
	return *this;
}

std::string Person::GetName() const
{
	return name;
}

void Person::AddResource()
{
	delete pResource;
	pResource = new Resource("Resource for " + GetName());
}

int main(int argc, char * argv[])
{
	Person Kate("Kate", 345);
	Kate.AddResource();
	Kate.SetName("Kate2");
	Kate.AddResource();

	Person Kate2 = Kate;
	Kate = Kate2;

	return 0;
}

