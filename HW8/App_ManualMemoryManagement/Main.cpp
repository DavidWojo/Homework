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


Resource::Resource(const std::string n) : name(n)
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
	std::string firstname;
	std::string lastname;
	int arbitrarynumber;
	Resource* pResource;

public:
	Person(const std::string first, const std::string last, int arbitrary);
	Person(const Person & p);
	~Person();
	Person& operator=(const Person & p);
	std::string GetName() const;
	int GetNumber() const { return arbitrarynumber; }
	void SetNumber(int number) { arbitrarynumber = number; }
	void SetFirstName(std::string first) { firstname = first; }
	void AddResource();
	std::string GetResourceName() const { return pResource ? pResource->GetName() : ""; }
};

Person::Person(const std::string first, const std::string last,
	int arbitrary) : firstname(first), lastname(last),
	arbitrarynumber(arbitrary), pResource(nullptr)
{
}

Person::Person(const Person & p)
{
	firstname = p.firstname;
	lastname = p.lastname;
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
	firstname = p.firstname;
	lastname = p.lastname;
	arbitrarynumber = p.arbitrarynumber;
	pResource = new Resource(p.pResource->GetName());
	return *this;
}


std::string Person::GetName() const
{
	return firstname + " " + lastname;
}


void Person::AddResource()
{
	delete pResource;
	pResource = new Resource("Resource for " + GetName());
}




int main(int argc, char * argv[])
{
	Person Kate("Kate", "Gregory", 345);
	Kate.AddResource();
	Kate.SetFirstName("Kate2");
	Kate.AddResource();

	Person Kate2 = Kate;
	Kate = Kate2;

	return 0;
}

