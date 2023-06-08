#include <iostream>

double hmean(double, double);

using namespace std;
int main()
{
	double x, y, z;

	cout << "두 수를 입력하십시오: ";
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
		}
		catch (const char* s)
		{
			cout << s << endl;
			cout << "두 수를 새로 입력하십시오: ";
			continue;
		}
		cout << x << ", " << y << "의 조화평균은 " << z << "입니다.\n";
		cout << "다른 두 수를 입력하십시오(끝내려면 q): ";
	}
	cout << "프로그램을 종료합니다.\n";

	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw "잘못된 hmean() 매개변수: a = -b는 허용되지 않습니다.\n";

	return 2.0 * a * b / (a + b);
}

/*
	- 예외 발생은, 그것이 함수 실행을 종료시킨다는 점에서 리턴 구문의 실행과 비슷하다.
	  그러나 예외 발생은, 호출한 프로그램에 제어를 넘기지 않고, 그 try블록이 포함되어 있는 함수를 발견할 때까지 
	  현재 호출한 함수들의 연쇄를 거슬러 올라간다.

	- 어떤 함수가 예외를 발생시키는데 try 블록이 없거나 데이터형이 일치하는 예외 핸들러가 없다면
	  프로그램은 기본적으로 abort()함수를 호출한다.
*/