#include "Atm.h"
#include <exception>

Atm::Atm(BankServer *pServer) :
	pBankServer(pServer)
{
}


Atm::~Atm()
{

}

bool Atm::WithDraw(int accountNumber, double amountToWithDraw)
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