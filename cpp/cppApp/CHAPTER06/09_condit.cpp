#include <iostream>

int main()
{
	using namespace std;

	int a, b;
	cout << "�� ���� ������ �Է��Ͻʽÿ�: ";
	cin >> a >> b;
	cout << "�� �߿��� �� ū ������ ";
	int c = a > b ? a : b;
	cout << c << "�Դϴ�.\n";

	return 0;
}