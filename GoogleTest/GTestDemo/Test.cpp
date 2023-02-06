#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::NiceMock;
using ::testing::Return;
using ::testing::_;

class BankServer
{
public :
	BankServer() {}
	virtual ~BankServer() {}
	virtual bool Connect() = 0;
	virtual void Disconnect() = 0;
	virtual double GetBalance(int accountNumber) = 0;
	virtual bool Debit(int accountNumber, double amountToDebit) = 0;
};

class BankServerMock : public BankServer
{
public:
	BankServerMock() {}
	MOCK_METHOD(bool, Connect, (), (override));
	MOCK_METHOD(void, Disconnect, (), (override));
	MOCK_METHOD(double, GetBalance, (int), (override));
	MOCK_METHOD(bool, Debit, (int, double), (override));
};

class Atm
{
public:
	Atm(BankServer *p) :
		pBankServer(p) { }
	bool WithDraw(int accountNumber, double amountToWithDraw)
	{
		bool result = pBankServer->Connect();
		if (result == false)
			return false;
		double currentBalance = pBankServer->GetBalance(accountNumber);
		if (currentBalance >= amountToWithDraw)
		{
			pBankServer->Debit(accountNumber, amountToWithDraw);
			result = true;
		}
		pBankServer->Disconnect();
		return result;
	}

private:
	BankServer* pBankServer;
};

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



int main(int argc, char** argv)
{
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}