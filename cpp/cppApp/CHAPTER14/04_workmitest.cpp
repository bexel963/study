#include <iostream>
#include <cstring>
#include "workermi.h"
const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	Worker* lolas[SIZE];

	int cnt;
	for (cnt = 0; cnt < SIZE; cnt++)
	{
		char choice;
		cout << "직종을 입력하십시오:\n"
			<< "w: 웨이터    s: 가수    t: 가수 겸 웨이터    q: 종료\n";
		cin >> choice;
		
		while (strchr("wstq", choice) == NULL)
		{
			cout << "w, s, t, q 중에서 하나를 선택하십시오: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w': 
			lolas[cnt] = new Waiter;
			break;
		case 's':
			lolas[cnt] = new Singer;
			break;
		case 't':
			lolas[cnt] = new SingingWaiter;
			break;
		}
		cin.get();
		lolas[cnt]->Set();
	}

	cout << "\n사원 현황은 다음과 같습니다:\n";
	for (int i = 0; i < cnt; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (int i = 0; i < cnt; i++)
		delete lolas[i];

	cout << "프로그램을 종료합니다.\n";

	return 0;

}