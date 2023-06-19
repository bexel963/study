#include <iostream>
#include "child.h"

int main()
{
	using namespace std;
	
	TableTennisPlayer player1("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
	
	rplayer1.Name();
	if (rplayer1.HasTable())
		cout << ": 탁구대가 있다.\n";
	else
		cout << ": 탁구대가 없다.\n";
	
	player1.Name();
	if (player1.HasTable())
		cout << ": 탁구대가 있다.\n";
	else
		cout << ": 탁구대가 없다.\n";

	cout << "이름: ";
	rplayer1.Name();
	cout << "; 랭킹: " << rplayer1.Rating() << endl;

	// TableTennisPlayer 객체를 사용하여 RatedPlayer를 초기화 한다.
	RatedPlayer rplayer2(1212, player1);
	cout << "이름: ";
	rplayer2.Name();
	cout << "; 랭킹: " << rplayer2.Rating() << endl;

	return 0;
}

/*
	- 파생 클래스와 기초 클래스의 관계
		1) 파생 클래스 객체는 기초 클래스 메서드들이 private이 아니면 그것들을 사용할 수 있다.
		2) 기초 클래스 포인터와 기초 클래스 참조는 명시적 데이터형 변환이 없어도 파생 클래스 객체를 참조할 수 있다.
			: 일반적으로 C++는 참조형과 포인터형이 대입되는 데이터형과 일치할 것을 요구하지만 상속의 경우에는 이 규칙이 완화된다.
			  그러나 이러한 규칙 완화는 일방 통행적이다. 즉, 파생 클래스의 참조와 포인터에 기초 클래스의 객체와 주소를 대입할 수 없다.

	- RatedPlayer olaf1(1840, "Olaf", "Loaf", true);
	  TableTennisPlayer olaf2(olaf1);
		: olaf2를 초기화하는 생성자의 정확한 원형은 TableTennisPlayer(const RatedPlayer&); 이다.
		  그런데 기초 클래스 선언에 이와 같은 생성자를 만들지 않았다.
		  이러한 경우, 암시적인 복사 생성자가 그 역할을 대신한다.
			-> TableTennisPlayer(const TableTennisPlayer&);	// 암시적인 복사 생성자.
		  이 복사 생성자는 RatedPlayer 객체 olaf1 안에 파묻혀 있는 TableTennisPlayer 객체로 olaf2를 초기화한다.

	- RatedPlayer olaf1(1840, "Olaf", "Loaf", true);
	  TableTennisPlayer winner;
	  winner = olaf1;
		: 이 경우, 프로그램은 다음과 같은 암시적인 오버로딩 대입 연산자를 대입에 사용한다.
			-> TableTennisPlayer& operator=(const TableTennisPlayer&) const;
		  olaf1의 기초 클래스 부분이 winner에 복사된다.
*/
