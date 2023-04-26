#include <iostream>
#include "stock_constructor.h"

int main()
{
	{
		using std::cout;
		cout << "�����ڸ� ����Ͽ� ���ο� ��ü���� �����Ѵ�.\n";

		Stock stock1("NanoSmart", 12, 20.0);
		stock1.show();

		Stock stock2 = Stock("Boffo Objects", 2, 2.0);
		stock2.show();
		cout << "----------------------------\n";

		cout << "stock1�� stock2�� �����Ѵ�.\n";
		/*
			- ����ü ���԰� ����������, Ŭ���� ��ü ������, �⺻������ �� ��ü�� ����� 
			  �ٸ� ��ü�� �����ϴ� ���̴�.
		*/
		stock2 = stock1;
		cout << "stock1�� stock2�� ����Ѵ�.\n";
		stock1.show();
		stock2.show();
		cout << "----------------------------\n";

		cout << "�����ڸ� ����Ͽ� ��ü�� �缳���Ѵ�.\n";
		/*
			- �����ڿ� ���� ȣ���� �ӽð�ü�� ���� �����ϰ�, �� �ӽ� ��ü�� stock1�� ����ȴ�.
			  �׷��� ���� �ӽ� ��ü�� ������. -> �ӽ� ��ü�� ���� �ı��� ȣ��
		*/
		stock1 = Stock("Nifty Foods", 10, 50.0);		// �ӽ� ��ü
		cout << "���ŵ� stock1:\n";
		stock1.show();
		cout << "----------------------------\n";

		cout << "���α׷��� �����մϴ�.\n";
		cout << "----------------------------\n";

		// ����Ʈ �ʱ�ȭ ���� ���
		Stock hot_tip = { "Derivatives Plus Plus", 100, 45.0 };
		Stock jock{ "Sport Age Storage, Inc" };
		Stock temp{ };
	}

	return 0;
}