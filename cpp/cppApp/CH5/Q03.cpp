#include <iostream>

using namespace std;

int main()
{
	int input;
	int sum = 0;

	cout << "수 하나 입력(끝내려면 0 입력): ";
	cin >> input;

	while (input != 0)
	{
		//cin.get();

		sum += input;

		cout << "수 하나 입력(끝내려면 0 입력): ";
		cin >> input;
	}

	cout << "입력한 수의 합: " << sum << endl;

	return 0;
}