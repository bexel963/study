#include <iostream>

int main()
{
	using namespace std;
	int rats = 101;
	int& rodents = rats;

	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	rodents++;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "rats�� �ּ� = " << &rats;
	cout << ", rodents�� �ּ� = " << &rodents << endl;

	return 0;
}

/*
	- C++�� ���� ������� ���ο� �������� �� �߰��ߴ�.
	  ������ �̸� ���ǵ� � ������ ���� �̸� ��� �� �� �ִ� ��� �̸��̴�.
	- ������ �ֵ� �뵵�� �Լ��� ���� �Ű������� ����ϴ� ���̴�.	
*/