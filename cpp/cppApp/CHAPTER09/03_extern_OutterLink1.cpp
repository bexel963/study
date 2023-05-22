#include <iostream>

using namespace std;

double warming = 0.3;	// 전역 변수(외부 변수) 선언

void update(double);
void local();

int main()
{
	cout << "전역 warming은 " << warming << "도입니다.\n";
	update(0.1);
	cout << "전역 warming은 " << warming << "도입니다.\n";
	local();
	cout << "전역 warming은 " << warming << "도입니다.\n";

	return 0;
}
