#include <iostream>

using namespace std;

int factorial(int);

int main()
{
	int num;

	cout << "정수 한 개 입력 (끝내려면 문자 하나 입력): ";
	while (cin >> num)
	{
		cout << "!" << num << " = " << factorial(num) << endl;
		cout << "정수 한 개 입력 (끝내려면 문자 하나 입력): ";
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