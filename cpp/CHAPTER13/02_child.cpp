#include "child.h"
#include <iostream>

using std::cout;

/*
	- public 파생에서는 기초 클래스의 public 멤버들이 파생 클래스의 public 멤버가 된다.
	- 기초 클래스의 private 부부늗ㄹ도 파생 클래스의 일부가 된다. 그러나 그들은 기초 클래스의 protected 메서드와 public 메서드를 통해서
	  간접적으로만 접근할 수 있다.
	- 파생 클래스형의 객체 안에는 기초 클래스형의 데이터 멤버들이 저장된다.
		-> 파생 클래스는 기초 클래스의 구현들을 상속받는다.
	- 파생 클래스형의 객체는 기초 클래스형의 메서드들을 사용할 수 있다.
		-> 파생 클래스는 기초 클래스의 인터페이스를 상속받는다.

	- 파생 클래스의 생성자에서는 새로 추가된 데이터 멤버와(있을 경우에..), 상속받은 데이터 멤버들에 데이터를 제공해야 한다.
	- 상속받은 데이터 멤버들에 데이터 제공하기
		1) 개별적인 형식 매개변수 사용
		2) 하나의 기초 클래스의 객체를 매개변수로 사용
*/

TableTennisPlayer::TableTennisPlayer(const string& fn, const string& ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht)
{
	
}


void TableTennisPlayer::Name() const
{
	cout << lastname << ", " << firstname;
}

RatedPlayer::RatedPlayer(unsigned int r, const string& fn, const string& ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
	rating = r;
}
/*
	- 파생 클래스의 생성자
		: 파생 클래스는 기초 클래스의 private멤버에 직접 접근할 수 없다. 기초 클래스의 메서드들을 통해서만 접근해야 한다.
			-> RatedPlayer 생성자는 상속받은 멤버들을 직접 설정할 수 없다.
			-> 즉, 파생 클래스의 생성자는 기초 클래스의 생성자를 사용해야 한다.
		: 프로그램이 파생 클래스의 객체를 생성할 때, 먼저 기초 클래스의 객체를 생성한다.
		  이것은 프로그램이 파생 클래스 생성자의 몸체 안으로 들어가기 전에, 기초 클래스 객체가 먼저 생성되어야 한다는 것을 의미한다.
		  C++은 이것을 하기 위해 멤버 초기자 리스트 문법을 사용한다.

	- RatedPlayer player(1140, "Mallory", "Duck", true);
		: 이 생성자는 실제 매개변수인 "Mallory", "Duck", true 를 형식 매개변수인 fn, ln, ht에 대입한다.
		  그러고 나서, 이 형식 매개변수들을 실제 매개변수 자격으로 TableTennisPlayer 생성자에 전달하고 기초 클래스의 객체가 생성된다.
		  그 후 파생 클래스의 생성자의 몸체 안으로 들어가 파생 클래스의 객체 생성을 완수한다.
			-> 파생 클래스의 생성자가 멤버 초기자 리스트를 통해 기초 클래스 생성자에 기초 클래스 정보를 제공해야 한다.

	- 멤버 초기자 리스트를 생략하면(기초 클래스 생성자를 호출하는 것을 생략하면), 프로그램은 디폴트 기초 생성자를 사용한다. 
	  그러므로 멤버 초기자 리스트를 작성하는 자리에 : TableTennisPlayer() 를 작성한 것과 결과가 같다.
		-> 디폴트 생성자를 사용하기를 원하지 않는다면, 올바른 기초 클래스 생성자 호출을 명시적으로 제공해야 한다.

	- 가장 기초 클래스의 경우를 제외하고, 파생 클래스는 인접한 직계 상위 기초 클래스에만 값을 전달할 수 있다.
	  멤버 초기자 리스트는 생성자에만 사용할 수 있다.
*/

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& tp) : TableTennisPlayer(tp), rating(r)
{
	
}
/*
	- TableTennisPlayer(tp)
		: tp 는 const TableTennisPlayer& 형이기 때문에, 이 호출은 기초 클래스의 복사 생성자를 호출한다.
		  그런데 기초 클래스에는 복사 생성자가 정의되어 있지 않다. 이와 같이 복사 생성자가 필요한데 그것을 정의하지 않았을 경우에,
		  컴파일러가 복사 생성자를 자동으로 생성한다. (12장)
		: 이 경우에는, 그 클래스가 동적 메모리 대입을 사용하고 있지 않기 때문에, 멤버별 복사를 수행하는 암시적 복사 생성자로 충분하다.
*/

/*
	- is-a 관계 (public 상속)
		: C++는 상속의 3가지 형식으로 public, protected, private 이다.
		: public 상속이 가장 일반적인 형식인데 이것은 is-a 관계를 나타낸다.
		  is-a 관계는 파생 클래스 객체가 기초 클래스 객체이기도 하다는 것을 뜻한다.
		  -> 기초 클래스 객체를 대상으로 수행할 수 있는 모든 작업을, 파생 클래스 객체에 대해서도 수행할 수 있다.

*/

