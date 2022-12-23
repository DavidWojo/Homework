#include <gtest/gtest.h>
#include "Person.h"
#include "Employee.h"


TEST(PersonTestSuite, TestPersonConstructorWithValidParams)
{
	EXPECT_NO_THROW(
		{
			Person p("John", "Smith", "111 - 22 - 3456");
			ASSERT_EQ("John", p.GetFirstName());
			ASSERT_EQ("Smith", p.GetLastName());
			ASSERT_EQ("111 - 22 - 3456", p.GetSocialSecurityNumber());
		}
	);
}

TEST(EmployeeTestSuite, TestEmployeeConstructorWithValidParams)
{
	EXPECT_NO_THROW(
		{
			Employee e("John", "Smith", "111 - 22 - 3456", "j76543");
			ASSERT_EQ("John", e.GetFirstName());
			ASSERT_EQ("Smith", e.GetLastName());
			ASSERT_EQ("111 - 22 - 3456", e.GetSocialSecurityNumber());
			ASSERT_EQ("j76543", e.GetEmployeeID());
		}
	);
}


TEST(PersonTestSuite, TestPersonConstructorWithInvalidFirstName)
{
	EXPECT_ANY_THROW(
		{
			Person p("", "Smith", "111 - 22 - 3456");
		}
	);
}

TEST(EmployeeTestSuite, TestEmployeeConstructorWithInvalidFirstName)
{
	EXPECT_ANY_THROW(
		{
			Employee e("", "Smith", "111 - 22 - 3456", "j76543");
		}
	);
}


TEST(PersonTestSuite, TestPersonConstructorWithInvalidLastName)
{
	EXPECT_ANY_THROW(
		{
			Person p("John", "", "111 - 22 - 3456");
		}
	);
}

TEST(EmployeeTestSuite, TestEmployeeConstructorWithInvalidLastName)
{
	EXPECT_ANY_THROW(
		{
			Employee e("John", "", "111 - 22 - 3456", "j76543");
		}
	);
}


TEST(PersonTestSuite, TestPersonConstructorWithInvalidSocialSecurityNumber)
{
	EXPECT_ANY_THROW(
		{
			Person p("John", "Smith", "");
		}
	);
}

TEST(EmployeeTestSuite, TestEmployeeConstructorWithInvalidSocialSecurityNumber)
{
	EXPECT_ANY_THROW(
		{
			Employee e("John", "Smith", "", "j76543");
		}
	);
}

TEST(EmployeeTestSuite, TestEmployeeConstructorWithInvalidEmployeeID)
{
	EXPECT_ANY_THROW(
		{
			Employee e("John", "Smith", "111-22-333", "");
		}
	);
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}