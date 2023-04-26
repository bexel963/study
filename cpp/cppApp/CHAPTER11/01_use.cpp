#include <iostream>
#include "mytime.h"

int main()
{
	using std::cout;
	using std::endl;
	Time planning;
	Time coding(5, 55);
	Time fixing(2, 40);
	Time total;
	Time diff;
	Time adjusted;
	
	cout << "planning time = ";
	planning.show();
	cout << endl;

	cout << "coding time = ";
	coding.show();
	cout << endl;

	cout << "fixing time = ";
	fixing.show();
	cout << endl;

	total = coding.sum(fixing);
	cout << "\"coding.sum(fixing)\" = ";
	total.show();
	cout << endl;

	cout << "================================================\n";

	total = coding + fixing;
	cout << "\"coding + fixing\" = ";
	total.show();
	cout << endl;

	cout << "\"coding.operator+(fixing)\" = ";
	total = coding.operator+(fixing);
	total.show();
	cout << endl;

	diff = coding - fixing;
	cout << "\"coding - fixing\" = ";
	diff.show();
	cout << endl;

	adjusted = total * 1.5;
	cout << "\"total * 1.5\" = ";
	adjusted.show();
	cout << endl;

	cout << "================================================\n";

	cout << total;
		
	return 0;
}