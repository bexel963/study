#include "parent.h"
#include <iostream>

using std::cout;

TableTennisPlayer::TableTennisPlayer(const string& fn, const string& ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht)
{
	cout << "객체 생성!!\n";
}
/*
	TableTennisPlayer::TableTennisPlayer(const string& fn, const string& ln, bool ht)
	{
		firstname = fn;
		lastname = ln;
		hasTable = ht;
	}
	- 이렇게 하면 firstname에 대한 디폴트 string 생성자를 부른 다음, string 대입 연산자를 불러서 firstname을 fn으로 다시 세팅한다.
	- 그러나 멤버 초기자 리스트 구문을 사용하면 string 복사 생성자를 사용하여 firstname을 fn으로 초기화하는 한 단계를 생략해준다.
*/



void TableTennisPlayer::Name() const
{
	cout << lastname << ", " << firstname;
}

