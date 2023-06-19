#include <iostream>
#include <cfloat>

bool hmean(double, double, double*);
using namespace std;

// 03_abort.cpp 와 비교...
int main()
{
	double x, y, z;
	
	cout << "두 수를 입력하십시오: ";
	while (std::cin >> x >> y)
	{
		if (hmean(x, y, &z))
			cout << x << ", " << y << "의 조화평균은 " << z << "입니다.\n";
		else
			cout << "서로 부정인 두 수의 조화평균은 구할 수 없다.\n";
		cout << "다른 두 수를 입력하십시오(끝내려면 q): ";
	}
	cout << "프로그램을 종료합니다.\n";

	return 0;
}

bool hmean(double a, double b, double* ans)
{
	if (a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	else
	{
		*ans = 2.0 * a * b / (a + b);

		return true;
	}
}

/*
	- 에러 코드 리턴
		: 예를들어, 보통 ostream 클래스의 get(void) 멤버는 다음 번에 입력되는 문자의 ASCII 코드를 리턴한다.
		  그러나 파일 끝을 만났을 경우에는 특수한 값인 EOF를 리턴한다.
		  이 접근 방식은 hmean()에는 적용되지 않는다. (수치 값만이 유효한 리턴값이 될 수 이다.)
		: hmean() 상황에서는, 포인터 매개변수 또는 참조 매개변수를 호출한 프로그램에 어떤 값을 보내는 데 사용하고,
		  함수 리턴값은 성공이나 실패를 알리는 데 사용할 수 있다.
		  오버로딩된 >> 연산자들의 istream 계열은 이 테크닉의 변형을 사용한다.
		: 성공이나 실패를 호출한 프로그램에 통지함으로써, 프로그램이 비정상 종료가 아닌 다른 조치를 취할 수 있게 한다.

		: 이 설계는 함수 리턴값을 검사하는 일을 프로그래머에게 맡기지만 프로그래머가 항상 리턴값을 검사하는 것은 아니다.
		  예를 들면 cout가 성공적으로 출력을 마쳤는지 확인하지 않는다.

		: 리턴 조건을 어딘가에 저장한다는 아이디어를 구현하는 또 한가지 방법은 전역 변수를 사용하는 것이다.
		  잠재적 문제를 안고 있는 그 함수는 일이 잘못된다면 그 전역 변수를 특정 값으로 설정할 수 있다.
		  이것이 전통적인 C 수학 라이브러리가 사용하는 방법이다. 거기서는 전역 변수 errno를 사용한다.
*/