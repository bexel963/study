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
		cout << revenuB << "원" << endl;
		deposit += revenuB;
		year++;
	}

	cout << "B가 " << year << "년 뒤에 A의 투자 가치를 초과한다.\n";

	return 0;

}