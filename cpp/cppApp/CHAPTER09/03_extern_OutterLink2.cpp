#include <iostream>

extern double warming;	// external.cpp에서 선언한 전역변수 warming을 사용

void update(double);
void local();

using std::cout;

void update(double dt)	// 전역 변수를 갱신한다.
{
	extern double warming;	// 선택적 재선언
	warming += dt;
	cout << "전역 warming이 " << warming << "도로 갱신되었습니다.\n";
}

void local()
{
	double warming = 0.8;
	
	cout << "지역 warming은 " << warming << "도입니다.\n";
	cout << "그러나, 전역 warming은 " << ::warming;
	cout << "도입니다.\n";
}