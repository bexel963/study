#include <iostream>

int main()
{
	using namespace std;

	char ch;
	int count = 0;
	cout << "���ڵ��� �Է��Ͻÿ�. �������� #�� �Է��Ͻÿ�: \n";
	cin >> ch;

	while (ch != '#')
	{
		cout << ch;
		++count;
		cin >> ch;
	}

	cout << endl << count << " ���ڸ� �о����ϴ�.\n";

	return 0;

}