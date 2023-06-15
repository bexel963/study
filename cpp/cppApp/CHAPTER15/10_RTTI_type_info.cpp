/*
	- typeid 연산자
		: 이 연산자를 사용하여 두 객체의 데이터형이 같은지 확인할 수 있다.
		  sizeof와 비슷하게, typeid 연산자는 두 종류의 매개변수를 받아들인다.
			1) 클래스의 이름
			2) 객체로 평가되는 식
		: typeid 연산자는 type_info 객체에 대한 참조를 리턴한다.
		  type_info는 typeinfo 헤더 파일에 정의되어 있는 클래스이다.
		: type_info 클래스는 데이터형을 비교하는 데 사용할 수 있도록 ==와 != 연산자를 오버로딩 한다.

				typeid(Magnificent) == typeid(*pg)

		: pg가 Magnificent 객체를 지시하는 포인터이면 true로 평가된다.
		  pg가 널 포인터면, 프로그램은 bad_typeid 예외를 발생시킨다.
		  이 예외 데이터형은 exception 클래스로부터 파생된 것이고, typeinfo 헤더 파일에 선언되어 있다.
		: type_info 클래스의 구현은 업체마다 다르지만, 일반적으로 클래스의 이름인, 시스템에 따른 문자열을 리턴하는 name() 멤버를 포함한다.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
using namespace std;

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
	srand(time(0));
	Grand* pg;
	Superb* ps;
	for (int i = 0; i < 5; i++)
	{
		pg = getOne();
		cout << "지금 " << typeid(*pg).name() << "형을 처리하고 있습니다.\n";
		pg->speak();
		if (ps = dynamic_cast<Superb*>(pg))
			ps->say();
		if (typeid(Magnificent) == typeid(*pg))
			cout << "그래, 너야말로 진짜 Magnificient 클래스이다.\n";
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
	- dynamic_cast와 가상 함수들을 무시하고 작성한 비효율적인 코드

				Grand* pg;
				Superb* ps;
				Magnificent* pm;
				for(int i=0 ; i<5 ; i++)
				{
					pg = getOne();
					if(typeid(Magnificent) == typeid(*pg))
					{
						pm = (Magnificent*)pg;
						pm->speak();
						pm->say();
					}
					else if(typeid(Superb) == typeid(*pg))
					{
						ps = (Superb*)pg;
						ps->speak();
						ps->say();
					else
						pg->speak();
				}
				
*/