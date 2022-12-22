#include <gtest/gtest.h>
#include "Person.h"


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

TEST(PersonTestSuite, TestPersonConstructorWithInvalidFirstName)
{
	EXPECT_ANY_THROW(
		{
			Person p("", "Smith", "111 - 22 - 3456");
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



int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}