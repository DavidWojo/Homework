#pragma once
#include "BankServer.h"

class Atm
{

public:
	Atm(BankServer *pServer);
	~Atm();
	bool WithDraw(int accountNumber, double amountToWithdraw);

private:
	BankServer *pBankServer;
};
