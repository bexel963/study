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

	cout << "�̸� �Է�(40�ڱ���..): ";
	cin.getline(g.fullname, Len-1);
	if (g.fullname[0] == ' ')
		return 0;
	cout << "�ڵ�ĸ �Է�: ";
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

	cout << "�̸�: " << g.fullname << endl;
	cout << "�ڵ�ĸ: " << g.handicap << endl;
}