/*
	- RTTI (runtime type identification)(실행 시간 데이터형 정보)
		: 프로그램이 실행 도중에 객체의 데이터형을 결정하는 표준 방법을 제공하는 것이다.

	- RTTI의 목적
		: 하나의 공통 기초 클래스로부터 상속된 클래스 계층이 있다고 가정하자. 이 클래스 계층에 속해 있는 클래스들의 어떤 객체를 
		  기초 클래스 포인터가 지시하도록 설정할 수 있다.
		  그 다음에, 어떤 정보를 처리한 후 이들 클래스들 중 어느 하나를 선택하고, 그 클래스형의 한 객체를 생성하고, 기초 클래스 포인터에
		  대입하기 위해 그 객체의 주소를 리턴하는 함수를 호출한다.
		  이 때, 그 포인터가 지시하는 객체의 종류가 무엇인지 어떻게 알 수 있을까....
		  (그 데이터형을 알고 싶은 이유는 어떤 클래스 메서드의 정확한 버전을 호출하고 싶기 때문이다...)

	- RTTI의 동작 방식
		: C++는 RTTI를 지원하는 세 가지 요소를 가지고 있다.

			1) dynamic_cast
				-> 기초 클래스형을 지시하는 포인터로부터 파생 클래스형을 지시하는 포인터를 생성한다.
				   가능하지 않다면, 널 포인터인 0을 리턴한다.

			2) typeid 연산자
				-> 어떤 객체의 정확한 데이터형을 식별하는 하나의 값을 리턴한다.

			3) type_info 구조체
				-> 어떤 특별한 데이터형에 대한 정보를 저장한다.

		: RTTI는 가상 함수들을 가지고 있는 클래스 계층에 대해서만 사용할 수 있다. 그 이유는, 그들이 파생 객체들의 주소를 기초 클래스 포인터들에 대입해야
		  하는 유일한 클래스 계층이기 때문이다.

	- 데이터형 변환이 안전한지 물어보는 것이, 어떤 종류의 객체를 지시하는지 물어보는 것보다 더 일반적이고 더 유용하다.
	  데이터형을 알려고 하는 일반적인 이유는, 어떤 특별한 메서드를 호출하는 것이 안전한지 알기 위한 것이다.
	  어떤 메서드를 호출하는 데 정확한 데이터형 일치가 반드시 필요한 것은 아니다.
	  그 메서드의 가상 버전을 위해 정의된 기초 데이터형이 그 데이터형이 될 수 있다.

				class Grand { //가상메서드들... };
				class Superb : public Grand { ... };
				class Magnificent : public Superb { ... };

				Grand* pg = new Grand;
				Grand* ps = new Superb;
				Grand* pm = new Magnificent;

				Magnificent* p1 = (Magnificent*)pm;	// 안전
				Magnificent* p2 = (Magnificent*)pg;	// 안전X
				Superb* p3 = (Magnificent*)pm;		// 안전

				=> public 파생은 Magnificent 객체가 Superb 객체(직접 기추)이고, Grand 객체(간접 기초)이기도 하다는 것을 보장한다.
*/

/*
	- dynamic_cast 연산자
		: 이것은 포인터가 지시하는 객체형이 무엇인지 알려 주지 않는다. 그 대신에 그 객체의 주소를 특정형의 포인터에 안전하게 대입할 수 있는지 알려 준다.

				Superb* pm = dynamic_cast<Superb*>(pg);

		: 이 코드는 포인터 pg가 Superb* 형으로 안전하게 변환될 수 있는지 의문을 제기한다.
	      변환될 수 있다면, 그 연산자는 그 객체의 주소를 리턴한다. 변환될 수 없다면, 널 포인터인 0을 리턴한다.

				dynamic_cast<Type*>(pt)

		: 포인터 pt에 의해 지시되는 객체(*pt)가 Type형이거나, Type형으로부터 직접 또는 간접적으로 파생된 객체일 경우에, 포인터 pt를 Type* 형의 포인터로 변환한다.
		  그렇지 않을 경우에, 이 표현은 널 포인터인 0으로 평가된다.						
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;

class Grand
{
private:
	int hold;
public:
	Grand(int h = 0) : hold(h) { }
	virtual void speak() const { cout << "나는 Grand 클래스이다!\n"; }
	virtual int value() const { return hold; }
};

class Superb : public Grand
{
public:
	Superb(int h = 0) : Grand(h) { }
	void speak() const { cout << "나는 Super 클래스이다.!\n"; }
	virtual void say() const { cout << "내가 가지고 있는 Superb 값은 " << value() << "이다.\n"; }
};

class Magnificent : public Superb
{
private:
	char ch;
public:
	Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) { }
	void speak() const { cout << "나는 Magnificent 클래스이다.!!!\n"; }
	void say() const { cout << "내가 가지고 있는 문자는 " << ch << "이고, 정수는 " << value() << "이다.\n"; }
};

Grand* getOne();

int main()
{
	std::srand(std::time(0));
	Grand* pg;
	Superb* ps;
	for (int i = 0; i < 5; i++)
	{
		pg = getOne();
		pg->speak();
		if (ps = dynamic_cast<Superb*>(pg))	// pg가 가리키는 객체가 Superb형 또는 Magnificent형 둘 중 어느 하나일 때 참이된다.
			ps->say();
	}
	return 0;
}

Grand* getOne()
{
	Grand* p;
	switch (std::rand() % 3)
	{
	case 0:
		p = new Grand(std::rand() % 100);
		break;
	case 1:
		p = new Superb(std::rand() % 100);
		break;
	case 2:
		p = new Magnificent(std::rand() % 100, 'A' + std::rand() % 26);
		break;
	default:
		p = new Grand(std::rand() % 100);		
	}

	return p;
}

/*
	- dynamic_cast를 참조와 함께 사용할 수도 있다. 
	  널 포인터형에 해당하는 참조값은 존재하지 않기 때문에, 실패를 나타내는 데 사용할 수 있는 특별한 참조값이 없다.
	  그 대신에 부적절한 요청이 제시될 때, dynamic_cast는 bad_cast형의 예외를 발생시킨다.
	  이 예외는, exception 클래스로부터 파생된 것이며, typeinfo 헤더 파일에 정의되어 있다.

				#include <typeinfo>
				...
				try
				{
					Superb& rs = dynamic_cast<Superb&>(rg);
					...
				}
				catch(bad_cast&)
				{
					...
				};
*/