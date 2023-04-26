#include <iostream>

inline double square(double x) { return x * x;  }

int main()
{
	using namespace std;
	double a, b;
	double c = 13.0;

	a = square(5.0);
	b = square(4.5 + 7.5);

	cout << "a = " << a << ", b = " << b << endl;
	cout << "c = " << c;
	cout << ", c의 제곱 = " << square(c++) << endl;
	cout << "현재 c = " << c << endl;

	return 0;
}

/*
	- 일반 함수는 프로그램의 실행 제어를 하나의 독립된 함수에게 넘긴다.
	- 인라인 함수는 함수 호출을 인라인 코드로 대체한다.
	- 인라인 함수에서는 컴파일된 함수 코드가 프로그램의 다른 코드 안에 직접 삽입되어 있다.
	  이것은 컴파일러가 함수 호출을 그에 대응하는 함수 코드로 대체한다는 것을 의미한다.

	- 인라인 함수는 일반 함수처럼 매개변수를 값으로 전달 받는다.
	- 매크로 함수는 매개변수를 넘겨받는 것이 아니라, 텍스트를 대체함으로써 동작한다.
*/