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

	cout << "�̸�: " << this->name << endl;
	cout << "���¹�ȣ: " << this->number << endl;
	cout << "�ܾ�: " << this->balance << endl;
	cout << endl;
}

void Account::deposit(double d)
{
	using std::cout;

	if (d < 0)
	{
		cout << "�Ա� �ݾ��� ������ �� �� �����ϴ�.\n";
		return;
	}
	balance += d;
}

void Account::withdraw(double d)
{
	using std::cout;

	if (d < 0)
	{
		cout << "��� �ݾ��� ������ �� �� �����ϴ�.\n";
		return;
	}
	if (balance < d)
	{
		cout << "�ܾ��� �����մϴ�. \n";
		return;
	}
	balance -= d;
}
