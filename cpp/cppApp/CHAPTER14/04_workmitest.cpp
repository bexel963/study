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
		cout << "������ �Է��Ͻʽÿ�:\n"
			<< "w: ������    s: ����    t: ���� �� ������    q: ����\n";
		cin >> choice;
		
		while (strchr("wstq", choice) == NULL)
		{
			cout << "w, s, t, q �߿��� �ϳ��� �����Ͻʽÿ�: ";
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

	cout << "\n��� ��Ȳ�� ������ �����ϴ�:\n";
	for (int i = 0; i < cnt; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (int i = 0; i < cnt; i++)
		delete lolas[i];

	cout << "���α׷��� �����մϴ�.\n";

	return 0;

}