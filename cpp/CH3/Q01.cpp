#include <iostream>

int main()
{
	using namespace std;
	
	int height;
	const int m = 100;

	cout << "Ű �Է�: ___cm\b\b\b\b\b";
	cin >> height;

	cout << height / m << "���� " << height % m << "��Ƽ����" << endl;

	return 0;
}