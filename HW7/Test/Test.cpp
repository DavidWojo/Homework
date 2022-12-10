#include <gtest/gtest.h>
#include "Person.h"


TEST(PersonTestSuite, PersonTestConstructorWithValidParams)
{
	Person p("John", "Smith", "111 - 22 - 3456");
}

TEST(PersonTestSuite, PersonTestConstructorWithInvalidFirstName)
{
	EXPECT_ANY_THROW(
		{
			Person p("", "Smith", "111 - 22 - 3456");
		}
	);
}

TEST(PersonTestSuite, PersonTestConstructorWithInvalidLastName)
{
	EXPECT_ANY_THROW(
		{
			Person p("John", "", "111 - 22 - 3456");
		}
	);
}

TEST(PersonTestSuite, PersonTestName2)
{
	Person p("John", "Smith", "111 - 22 - 3456");
	p.SetFirstName("David");
	ASSERT_EQ("David", p.GetFirstName());
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}