#include <iostream>

const int Max = 5;

int main()
{
	using namespace std;

	int golf[Max];
	cout << "���� ������ �Է��Ͻʽÿ�.\n";
	cout << "�� " << Max << " ���� ������ �Է��ؾ� �մϴ�.\n";
	
	int i;
	for (i = 0; i < Max; i++)
	{
		cout << "round #" << i + 1 << ": ";
		while (!(cin >> golf[i]))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "���� ������ �Է��Ͻʽÿ�: ";
		}
				
	}
	double total = 0.0;
	for (i = 0; i < Max; i++)
		total += golf[i];

	cout << "�� " << Max << "������ ��� ���� = " << total / Max << endl;

	return 0;
}