#include <iostream>

using namespace std;

const int SIZE = 12;

int main()
{
	const char* months[SIZE] =
	{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	int amount[SIZE];
	int sum = 0;

	cout << "<���� �Ǹŷ� �Է�>" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << months[i] << ": ";
		cin >> amount[i];
	}
	for (int i = 0; i < SIZE; i++)
		sum += amount[i];

	cout << "���� �� �Ǹŷ�: " << sum << "��" << endl;

	return 0;
	
}