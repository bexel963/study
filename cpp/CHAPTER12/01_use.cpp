#include <iostream>
#include "stringbad.h"
using std::cout;

void callme1(StringBad&);
void callme2(StringBad);

int main()
{
	using std::endl;

	{
		cout << "내부 블록을 시작한다.\n";
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

		cout << "하나의 객체를 다른 객체로 초기화: \n";
		StringBad sailor = sports;	// 복사 생성자가 정의 안 되어있으면 컴파일러가 자동으로 제공하는 복사 생성자가 사용됨.
		cout << "sailor: " << sailor << endl;
		cout << "-----------------\n";

		cout << "하나의 객체를 다른 객체에 대입: \n";
		StringBad knot;
		knot = headline1;			// 대입 연산자가 정의 안 되어있으면 컴파일러가 자동으로 제공하는 대입 연산자가 사용됨.
		cout << "knot: " << knot << endl;
		cout << "-----------------\n";

		cout << "이 블록을 빠져나온다.\n";
	}
	cout << "main()의 끝\n";

	return 0;
}

void callme1(StringBad& rsb)
{
	cout << "참조로 전달된 StringBad:\n";
	cout << "      \"" << rsb << "\"\n";
}
void callme2(StringBad sb)
{
	cout << "값으로 전달된 StringBad:\n";
	cout << "      \"" << sb << "\"\n";
}

