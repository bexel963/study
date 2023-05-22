#include <iostream>

unsigned int c_in_str(const char*, char);

int main()
{
	using namespace std;
	char mmm[15] = "minimun";

	const char* wail = "ululate";

	unsigned int ms = c_in_str(mmm, 'm');
	unsigned int us = c_in_str(wail, 'u');
	cout << mmm << "에는 m이 " << ms << "개 들어있습니다.\n";
	cout << wail << "에는 u가 " << us << "개 들어있습니다.\n";

	return 0;
}

unsigned int c_in_str(const char* str, char ch)
{
	int count = 0;

	while (*str)	// => str가 '\0'이면 루프를 탈출한다.  '\0' 의 수치 코드는 0이다.
	{
		if (*str == ch)
			count++;
		str++;
	}

	return count;
}

/*
	- C스타일 문자열을 나타내는 방법 3가지
		1) char형의 배열
			char ghost[15] = "galloping";
		2) 큰따옴표로 묶은 문자열 상수(문자열 리터럴)
			"gamboling"
		3) 문자열의 주소로 설정된 char형을 지시하는 포인터
			char* str = "galumphing"

		=> 3 가지 모두 char형을 지시하는 포인터이다. 따러서 이 세 가지 모두 문자열 처리 함수에 매개변수로 사용할 수 있다.
			int n1 = strlen(ghost);
			int n2 = strlen(str);
			int n3 = strlen("gamboling");

	- C 스타일 문자열과 일반 배열의 중요한 차이점은 문자열에는 종결 문자가 들어 있다는 것이다.
	  따라서 문자열의 크기는 매개변수로 전달할 필요가 없다.
	  그 대신에 함수는 루프를 사용하여 널 종결 문자에 도달할 때까지 차례로 문자들을 검사해야 한다.
*/