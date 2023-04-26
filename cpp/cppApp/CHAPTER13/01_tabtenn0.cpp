#include "tabtenn0.h"
#include <iostream>

using std::cout;

TableTennisPlayer::TableTennisPlayer(const string& fn, const string& ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht)
{
	cout << "��ü ����!!\n";
}

void TableTennisPlayer::Name() const
{
	cout << lastname << ", " << firstname;
}