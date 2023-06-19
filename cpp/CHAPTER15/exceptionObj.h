/*
	- 기하 평균: 두 수의 곱의 제곱근.
*/
#include <iostream>

class bad_hmean
{
private: 
	double v1;
	double v2;
public:
	bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) { }
	void mesg();
};

inline void bad_hmean::mesg()
{
	std::cout << "hmean(" << v1 << ", " << v2 << "): " << "잘못된 매개변수: a = -b\n";
}

class bad_gmean
{
public:
	double v1;
	double v2;
	bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) { }
	const char* mesg();
};

inline const char* bad_gmean::mesg()
{
	return "gmean() 매개변수들은 >= 0 이어야 합니다.\n";
}

/*
	- 일반적으로, 예외를 발생시키는 함수들은 객체를 발생시킨다.
	  그래서 서로 다른 예외 데이터형을 사용함으로써 서로 다른 함수들과 예외를 발생시키는 상황을 구별할 수 있게된다.
	  또한, 객체 자체에 정보를 전달할 수 있다.
	  사용자는 이 정보를 사용하여 예외가 발생하는 여러 조건들을 식별할 수 있다.
*/