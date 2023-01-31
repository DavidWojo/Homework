#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Atm.h"
#include "BankServerMock.h"

using ::testing::NiceMock;
using ::testing::Return;
using ::testing::_;


TEST(AtmTestSuite, TestBankServerMockUsingDefaultBehavior)
{
	NiceMock<BankServerMock> bankServerMock;
	Atm atm(&bankServerMock);
	ASSERT_TRUE(atm.WithDraw(1234, 100));
}

TEST(AtmTestSuite, TestBankServerMockUsingDefinedBehaviorVer1)
{
	NiceMock<BankServerMock> bankServerMock;
	Atm atm(&bankServerMock);
	ON_CALL(bankServerMock, GetBalance(1234)).WillByDefault(Return(2000));
	ASSERT_TRUE(atm.WithDraw(1234, 100));
}
