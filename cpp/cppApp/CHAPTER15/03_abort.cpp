#include <iostream>
#include <cstdlib>

double hmean(double a, double b);

int main()
{
	double x, y, z;

	std::cout << "두 수를 입력하십시오: ";
	while (std::cin >> x >> y)
	{
		z = hmean(x, y);
		std::cout << x << ", " << y << "의 조화평균은 " << z << "입니다.\n";
		std::cout << "다른 두 수를 입력하십시오(끝내려면 q): ";
	}
	std::cout << "프로그램을 종료합니다.\n";

	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
	{
		std::cout << "매개변수들을 hmean()에 전달할 수 없습니다.\n";
		std::abort();
		// hmean()에서 abort()를 호출하는 것은, main() 으로 다시 돌아가는 일 없이 그 프로그램을 직접 종료한다.
	}

	return 2.0 * a * b / (a + b);
}

/*
	- 두 수의 조화평균은 역수들의 평균의 역수로 정의한다.
*/

/*
	- abort() 함수의 원형은 cstdlib 헤더 파일에 들어 있다. 일반적으로 abort()는 호출되었을 때 표준 에러 스트림(cerr가 사용하는 스트림)에 
	  "abnormal program temination" (비정상적인 프로그램 종료)과 같은 메시지를 보내고 프로그램을 종료시키도록 구현되어 있다.
	  또한 이 함수는 그 프로그램이 다른 프로그램에 의해 기동되었을 경우에, 그 프로그램을 기동시킨 부모 프로세스나 운영체제에 컴파일러에 종속적인 어떤 값을 리턴한다.
*/