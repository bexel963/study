#include <iostream>

int main()
{
	using namespace std;

	int rats = 101;
	int& rodents = rats;

	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "rats�� �ּ� = " << &rats;
	cout << ", rodents�� �ּ� = " << &rodents << endl;

	int bunnies = 50;
	rodents = bunnies;	// ������ ���Թ��� �ƴ϶� �ʱ�ȭ ���� ���ؼ��� ������ �� �ִ�.                                          
	cout << "bunnies = " << bunnies;
	cout << ", rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "bunnies�� �ּ� = " << &bunnies;
	cout << ", rodents�� �ּ� = " << &rodents;
	cout << ", rats�� �ּ� = " << &rats;

	return 0;
}