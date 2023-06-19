#include <iostream>

using namespace std;

int main()
{
	int rows;

	cout << "출력할 행 수를 입력하십시오: ";
	cin >> rows;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows - i - 1; j++)
			cout << ' ';
		for (int j = 0; j < i + 1; j++)
			cout << '*';
		cout << endl;
	}

	return 0;
}