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
/*
	- ������ ������ �� �� ������ �ʱ�ȭ�ؾ� �Ѵ�. �����͸� ������ ��ó��, ������ ���� �����ϰ� ���߿� ���� ������ ���� ����.
	- ������ const �����Ϳ� ����ϴ�.
	  ������ ���� �� �ݵ�� �ʱ�ȭ�� �ؾ��ϰ�, �ϴ� � Ư�� ������ ����Ǹ� �װ��� ����ؾ� �Ѵ�.

	- ��, ������ ���Թ��� �ƴ϶� �ʱ�ȭ ���� ���ؼ��� ������ �� �ִ�.
			
			int rats = 101;
			int* pt = &rats;

			int& rodents = *pt;

			int bunnies = 50;
			pt = &bunnies;

	  rodents�� *pt�� �ʱ�ȭ�ϸ�, rodents�� rats�� �����Ѵ�. �̾ pt�� bunnies�� �����ϵ��� �����ص� rodents�� rats�� �����Ѵٴ� ����� ������ �ʴ´�.
*/