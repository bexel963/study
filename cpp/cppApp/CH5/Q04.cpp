#include <iostream>

using namespace std;

const float DRATE = 0.1;
const float BRATE = 0.05;

int main()
{
	float deposit = 100000;
	int year = 0;
	float revenuA = 0, revenuB = 0;

	revenuA = deposit * DRATE;

	while (revenuB < revenuA)
	{		
		revenuB = deposit * BRATE;
		cout << revenuB << "��" << endl;
		deposit += revenuB;
		year++;
	}

	cout << "B�� " << year << "�� �ڿ� A�� ���� ��ġ�� �ʰ��Ѵ�.\n";

	return 0;

}