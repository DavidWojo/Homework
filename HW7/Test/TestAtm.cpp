#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Atm.h"
#include "BankServerMock.h"

using ::testing::NiceMock;
using ::testing::Return;
using ::testing::_;


TEST(AtmTestSuite, TestBankServerMockDefaultBehavior)
{
	constexpr int accountNumber = 1234;
	NiceMock<BankServerMock> bankServerMock;
	Atm atm(&bankServerMock);
	ASSERT_FALSE(atm.WithDraw(accountNumber, 1000));
}

TEST(AtmTestSuite, TestBankServerMockDefinedBehavior)
{
	NiceMock<BankServerMock> bankServerMock;
	constexpr int accountNumber = 1234;
	Atm atm(&bankServerMock);
	ON_CALL(bankServerMock, GetBalance(accountNumber)).WillByDefault(Return(2000));
	ON_CALL(bankServerMock, Connect).WillByDefault(Return(true));
	ASSERT_TRUE(atm.WithDraw(accountNumber, 1000));
}
