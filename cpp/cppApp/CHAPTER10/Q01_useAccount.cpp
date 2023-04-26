#include <iostream>
#include "Q01_account.h"

int main()
{
	using std::cout;

	Account act1 = Account("임재형", "123-456-789", 7300000);
	Account act2("임선민", "789-456-123", 20000000);
	Account act3("임지선", "999-999-12999", 200000000);
	
	act1.show();
	act2.show();
	act3.show();
	
	cout << "---------------------------\n";

	act1.deposit(200000000);
	act2.withdraw(20000000);
	act3.withdraw(200000000);

	act1.show();
	act2.show();
	act3.show();



	return 0;
}