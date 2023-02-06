#pragma once

class BankServer
{
public:
	BankServer() {};
	virtual ~BankServer() {};
	virtual bool Connect() = 0;
	virtual double GetBalance(int accountNumber) = 0;
	virtual bool Debit(int accountNumber, double amount) = 0;
	virtual void Disconnect() = 0;
};
