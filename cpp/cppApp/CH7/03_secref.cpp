#include <iostream>

int main()
{
	using namespace std;

	int rats = 101;
	int& rodents = rats;

	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "rats의 주소 = " << &rats;
	cout << ", rodents의 주소 = " << &rodents << endl;

	int bunnies = 50;
	rodents = bunnies;	// 참조는 대입문이 아니라 초기화 선언에 의해서만 설정할 수 있다.                                          
	cout << "bunnies = " << bunnies;
	cout << ", rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "bunnies의 주소 = " << &bunnies;
	cout << ", rodents의 주소 = " << &rodents;
	cout << ", rats의 주소 = " << &rats;

	return 0;
}