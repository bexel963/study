/*
	- ���� �� �� �Է� ����.
		: �� �� ���� ������ ���� �Է��Ѵٰ� ����
	- �Է¹��� �� ������ �����Ͽ� �� ���̿� �ִ� ��� �������� ���� ���
*/
#include <iostream>

using namespace std;

int main()
{
	int n1, n2;
	int sum = 0;
	
	cout << "���� �ΰ� �Է�(����1 ����2): ";

	cin >> n1;
	cin >> n2;

	for (int i = n1; i <= n2; i++)
		sum += i;

	cout << n1 << "���� " << n2 << "���̿� �ִ� ��� �������� ��: " << sum << endl;
	
	return 0;
}