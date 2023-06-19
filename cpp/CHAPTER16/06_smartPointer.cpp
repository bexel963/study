/*
	auto_ptr<string> ps(new string("I reigned lonely as a cloud."));
	auto_ptr<string> vocation;
	vocation = ps;		// error

		: 프로그램이 같은 객체에 대해 두 번 해제를 시도하기 때문에 에러난다.
		  (ps가 수명을 다했을 때 한번, vocation이 수명을 다했을 때 한 번)

	- 위 문제를 해결하는 방법
		1) 복사를 수행하도록 대입 연산자를 정의한다.
		   그러면 한 객체가 다른 객체의 복사본이 되므로, 두 포인터는 서로 다른 객체를 지시하게 된다.
		2) 하나의 스마트 포인터만이 특정 객체를 소유할 수 있도록 소유권 개념을 도입한다.
		   스마트 포인터가 그 객체를 소유하고 있는 경우에만, 파괴자가 그 객체를 삭제한다.
		   그러고 나서, 대입을 통해 소유권을 이전시킨다.
		   이것이 auto_ptr, unique_ptr에서 사용하는 전략이다.
		3) 하나의 특정한 객체를 참조하는 스마트 포인터들이 몇 개인지 추적하는 훨씬 더 똑똑한 스마트 포인터를 생성한다.
		   이것을 참조 카운팅이라 한다. 대입할 때마다 참조 카운팅이 1씩 증가한다.
		   어떤 스마트 포인터의 수명이 다할 때마다 참조 카운팅이 1씩 감소된다.
		   따라서 마지막 스마트 포인터의 수명이 다했을 때 delete가 호출된다.
		   이것이 shared_ptr 전략이다.
*/

#include <iostream>
#include <string>
#include <memory>

int main()
{
	using namespace std;
	auto_ptr<string> films[5] =
	{
		auto_ptr<string>(new string("Fowl Balls")),
		auto_ptr<string>(new string("Duck Walks")),
		auto_ptr<string>(new string("Chicken Runs")),
		auto_ptr<string>(new string("Turkey Errors")),
		auto_ptr<string>(new string("Goose Eggs"))
	};
	auto_ptr<string> pwin;
	pwin = films[2];		// films[2]가 소유권을 읽음	=> films[2]가 더 이상 그 문자열을 참조하지 않는다. (null)	=> 이를 참조하려 하면 프로그램 크래시(Crash) 발생.
	/*
		- auto_ptr 대신에 shared_ptr을 사용하면 제대로 실행된다.
		  (shared_ptr을 사용하려면, C++11 shared_ptr 클래스를 지원하는 컴파일러가 필요하다.)

			: pwin = films[2]; 시점에서 pwin과 films[2]는 같은 객체를 가리키고 있다. 그리고, 참조 카운트가 1에서 2로 올라간다.
			  프로그램의 마지막에, 파괴자는 마지막으로 선언된 pwin이라는 첫 번째 객체를 호출해야 한다.
			  파괴자는 참조 카운트를 1로 줄인다. 그리고 shared_ptr의 배열의 멤버들이 해제된다.
			  마지막으로, films[2]의 파괴자는 참조 카운트를 0으로 만들고 대입된 메모리를 해제한다.
	*/

	cout << "다음은 최고의 조류 영화상 후보입니다.\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;

	cout << "수상자는 " << *pwin << "!\n";
	cin.get();

	return 0;
}

/*
	- unique_ptr은 auto_ptr처럼 소유권 개념을 가지고 있다.
	  그러나 unique_ptr은 프로그램 크래시가 발생하는 것이 아니라, 해당 구문에서 컴파일 에러가 발생한다.

			pwin = films[2];	// compile error
*/