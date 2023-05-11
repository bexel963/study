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
/*
	- 참조를 선언할 때 그 참조를 초기화해야 한다. 포인터를 선언할 때처럼, 참조를 먼저 선언하고 나중에 값을 지정할 수는 없다.
	- 참조는 const 포인터와 비슷하다.
	  참조를 만들 때 반드시 초기화를 해야하고, 일단 어떤 특정 변수에 연결되면 그것을 고수해야 한다.

	- 즉, 참조는 대입문이 아니라 초기화 선언에 의해서만 설정할 수 있다.
			
			int rats = 101;
			int* pt = &rats;

			int& rodents = *pt;

			int bunnies = 50;
			pt = &bunnies;

	  rodents를 *pt로 초기화하면, rodents가 rats를 참조한다. 이어서 pt가 bunnies를 지시하도록 변경해도 rodents가 rats를 참조한다는 사실은 변하지 않는다.
*/