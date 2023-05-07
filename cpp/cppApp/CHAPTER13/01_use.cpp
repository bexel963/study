#include <iostream>
#include "parent.h"

int main()
{
	using std::cout;
	TableTennisPlayer player1("Chuck", "Blizzard", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);
	/*
		- 생성자 선언에서 매개변수들의 타입은 const string& 형으로 선언 되어있다.
		  이것은 잘못 연결된 자료형이자만, 표준 string클래스는 12장의 String클래스와 흡사하게 const char* 형의 매개변수를 지닌 생성자를 가지고 있다.
		  그리고 이 생성자는 C스타일 string으로 초기화된 string 객체를 생성하기 위해 자동으로 사용된다.
		  즉, TableTennisPlayer 생성자에 대한 매개변수로 C스타일 string 이나 string 객체 두 가지 중 어떤 것을 사용해도 무방하다.
		- string 객체는 const string& 형의 매개변수를 지닌 string 생성자를 불러오고, C스타일 string은 const char* 형의 매개변수를 지닌 string 생성자를 불러온다.
	*/

	player1.Name();
	if (player1.HasTable())
		cout << ": 탁구대가 있다.\n";
	else
		cout << ": 탁구대가 없다.\n";
	player2.Name();
	if (player2.HasTable())
		cout << ": 탁구대가 있다.\n";
	else
		cout << ": 탁구대가 없다.\n";

	return 0;
}