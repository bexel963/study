#include <string>

using std::string;

class Account
{
private:
	string name;
	string number;
	int balance;

public:
	Account();
	Account(const string&, const string&, double);
	
	void show() const;
	void deposit(double);
	void withdraw(double);
	
};
