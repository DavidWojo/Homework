#include <gtest/gtest.h>
#include "Person.h"


TEST(PersonTestSuite, PersonTestName1)
{
	Person p("John", "Smith", "111 - 22 - 3456");
	ASSERT_EQ(1, 1);
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}