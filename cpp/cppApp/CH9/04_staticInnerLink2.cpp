#include <iostream>

extern int tom;				// 외부 변수 사용
static int dick = 10;		// 정적 변수, 내부링크	
int harry = 200;			// 정적 변수, 외부링크 (외부 변수 정의)

void remote_access()
{
	using namespace std;
	cout << "remote_access()가 보고하는 세 변수의 주소: \n";
	cout << &tom << " = &tom, " << &dick << " = &dick, " << &harry << " = &harry\n";
}