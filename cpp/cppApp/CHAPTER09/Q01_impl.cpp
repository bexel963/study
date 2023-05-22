#include <iostream>
#include <cstring>
#include "Q01.h"

void setgolf(golf& g, const char* name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf& g)
{
	using std::cout;
	using std::cin;

	cout << "이름 입력(40자까지..): ";
	cin.getline(g.fullname, Len-1);
	if (g.fullname[0] == ' ')
		return 0;
	cout << "핸디캡 입력: ";
	cin >> g.handicap;
	cin.get();

	return 1;
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	using std::cout;
	using std::endl;

	cout << "이름: " << g.fullname << endl;
	cout << "핸디캡: " << g.handicap << endl;
}