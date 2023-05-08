#include <iostream>

int main()
{
	using namespace std;
	int rats = 101;
	int& rodents = rats;

	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	rodents++;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "rats의 주소 = " << &rats;
	cout << ", rodents의 주소 = " << &rodents << endl;

	return 0;
}

/*
	- C++는 참조 변수라는 새로운 복합형을 언어에 추가했다.
	  참조는 미리 정의된 어떤 변수의 실제 이름 대신 쓸 수 있는 대용 이름이다.
	- 참조의 주된 용도는 함수의 형식 매개변수에 사용하는 것이다.	
*/