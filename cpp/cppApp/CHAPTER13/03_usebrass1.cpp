#include <iostream>
#include "brass.h"

int main()
{
	using std::cout;
	using std::endl;

	Brass Piggy("Porcelot Pigg", 381299, 4000.00);
	BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
	Piggy.ViewAcct();
	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;

	cout << "Hogg ¾¾ÀÇ °èÁÂ¿¡ $1000 ÀÔ±Ý:\n";
	Hoggy.Deposit(1000.00);
	cout << "Hogg ¾¾ÀÇ ÇöÀç ÀÜ¾×: $" << Hoggy.Balance() << endl << endl;

	cout << "Pigg ¾¾ÀÇ °èÁÂ¿¡¼­ $4200 ÀÎÃâ:\n";
	Piggy.Withdraw(4200.00);
	cout << "Pigg ¾¾ÀÇ ÇöÀç ÀÜ¾×: $" << Piggy.Balance() << endl << endl;

	cout << "Hogg ¾¾ÀÇ °èÁÂ¿¡¼­ $4200 ÀÎÃâ:\n";
	Hoggy.Withdraw(4200.00);
	Hoggy.ViewAcct();

	return 0;
	
}