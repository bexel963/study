#include <iostream>

int main()
{
	using namespace std;

	int auks, bats, coots;

	auks = 19.99 + 11.99;

	bats = (int)19.99 + (int)11.99;
	coots = int(19.99) + int(11.99);
	cout << "�ٴٿ��� = " << auks << ", ���� = " << bats << ", �˵տ��� = " << coots << endl;

	char ch = 'Z';
	cout << "�ڵ� " << ch << "�� ���� " << int(ch) << endl;
	cout << "��, �ڵ� Z�� ���� " << static_cast<int>(ch) << endl;

	return 0;
}