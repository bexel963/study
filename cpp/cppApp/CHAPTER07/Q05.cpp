#include <iostream>

using namespace std;

int factorial(int);

int main()
{
	int num;

	cout << "���� �� �� �Է� (�������� ���� �ϳ� �Է�): ";
	while (cin >> num)
	{
		cout << "!" << num << " = " << factorial(num) << endl;
		cout << "���� �� �� �Է� (�������� ���� �ϳ� �Է�): ";
	}

	return 0;
}

int factorial(int n)
{
	if (n == 0)
		return 1;
	if(n >= 1)
		return n * factorial(n - 1);
}