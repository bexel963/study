#include <iostream>

using namespace std;

const int SIZE = 12;
const int YEARS = 3;

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
	int amount[YEARS][SIZE];
	int sum[YEARS] = { 0 };
	int total = 0;

	cout << "<���� �Ǹŷ� �Է�>" << endl;
	for (int y = 0; y < YEARS; y++)
	{
		cout << "<" << y + 1 << "��°>" << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cout << months[i] << ": ";
			cin >> amount[y][i];
		}
		for (int i = 0; i < SIZE; i++)
			sum[y] += amount[y][i];
		
		total += sum[y];

		cout << y + 1 << "��° �Ǹŷ�: " << sum[y] << "��" << endl;
		cout << y + 1 << "��° �Ǹŷ����� ����: " << total << "��" << endl;
	}
	
	return 0;

}