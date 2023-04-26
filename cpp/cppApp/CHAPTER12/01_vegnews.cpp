#include <iostream>
#include "stringbad.h"
using std::cout;

void callme1(StringBad&);
void callme2(StringBad);

int main()
{
	using std::endl;
	{
		cout << "���� ������ �����Ѵ�.\n";
		StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuce Prey");
		StringBad sports("Spinach Leaves Bowl for Dollars");
		
		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;
		
		cout << "\n\n";
		callme1(headline1);
		cout << "headline1: " << headline1 << endl;
		cout << "\n";
		callme2(headline2);
		cout << "headline2: " << headline2 << endl;
		cout << "\n";

		cout << "-----------------\n";

		cout << "�ϳ��� ��ü�� �ٸ� ��ü�� �ʱ�ȭ: \n";
		StringBad sailor = sports;
		cout << "sailor: " << sailor << endl;
		cout << "-----------------\n";

		cout << "�ϳ��� ��ü�� �ٸ� ��ü�� ����: \n";
		StringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;
		cout << "-----------------\n";

		cout << "�� ������ �������´�.\n";
	}
	cout << "main()�� ��\n";

	return 0;
}

void callme1(StringBad& rsb)
{
	cout << "������ ���޵� StringBad:\n";
	cout << "      \"" << rsb << "\"\n";
}
void callme2(StringBad sb)
{
	cout << "������ ���޵� StringBad:\n";
	cout << "      \"" << sb << "\"\n";
}