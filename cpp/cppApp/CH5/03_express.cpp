#include <iostream>

int main()
{
	using namespace std;

	int x;

	cout << "���� ǥ���� x = 100�� ���� " << (x = 100) << endl;
	cout << "���� x�� ���� " << x << endl;
	cout << "���� ǥ���� x < 3 �� �������� " << (x < 3) << endl;
	cout << "���� ǥ���� x > 3 �� �������� " << (x > 3) << endl;
	
	cout.setf(ios_base::boolalpha);
	
	cout << "���� ǥ���� x < 3 �� bool���� " << (x < 3) << endl;
	cout << "���� ǥ���� x > 3 �� bool���� " << (x > 3) << endl;

	return 0;
}