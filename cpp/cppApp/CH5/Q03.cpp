#include <iostream>

using namespace std;

int main()
{
	int input;
	int sum = 0;

	cout << "�� �ϳ� �Է�(�������� 0 �Է�): ";
	cin >> input;

	while (input != 0)
	{
		//cin.get();

		sum += input;

		cout << "�� �ϳ� �Է�(�������� 0 �Է�): ";
		cin >> input;
	}

	cout << "�Է��� ���� ��: " << sum << endl;

	return 0;
}