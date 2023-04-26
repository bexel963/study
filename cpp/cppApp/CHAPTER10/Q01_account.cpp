#include <iostream>
#include "Q01_account.h"

Account::Account()
{
	name = "";
	number = "";
	balance = 0.0;
}
Account::Account(const string& name, const string& number, double balance)
{
	this->name = name;
	this->number = number;
	this->balance = balance;
}

void Account::show() const
{
	using std::cout;
	using std::endl;

	cout << "이름: " << this->name << endl;
	cout << "계좌번호: " << this->number << endl;
	cout << "잔액: " << this->balance << endl;
	cout << endl;
}

void Account::deposit(double d)
{
	using std::cout;

	if (d < 0)
	{
		cout << "입금 금액이 음수가 될 수 없습니다.\n";
		return;
	}
	balance += d;
}

void Account::withdraw(double d)
{
	using std::cout;

	if (d < 0)
	{
		cout << "출금 금액이 음수가 될 수 없습니다.\n";
		return;
	}
	if (balance < d)
	{
		cout << "잔액이 부족합니다. \n";
		return;
	}
	balance -= d;
}
