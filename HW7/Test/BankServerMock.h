#pragma once
#include <gmock/gmock.h>
#include "BankServer.h"

class BankServerMock : public BankServer
{

public:
	BankServerMock() {}
	MOCK_METHOD0(Connect, bool(void));
	MOCK_METHOD0(Disconnect, void(void));
	MOCK_METHOD1(GetBalance, double(int));
	MOCK_METHOD2(Debit, bool(int, double));
};
