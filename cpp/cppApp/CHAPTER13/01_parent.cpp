#include "parent.h"
#include <iostream>

using std::cout;

TableTennisPlayer::TableTennisPlayer(const string& fn, const string& ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht)
{
	cout << "��ü ����!!\n";
}
/*
	TableTennisPlayer::TableTennisPlayer(const string& fn, const string& ln, bool ht)
	{
		firstname = fn;
		lastname = ln;
		hasTable = ht;
	}
	- �̷��� �ϸ� firstname�� ���� ����Ʈ string �����ڸ� �θ� ����, string ���� �����ڸ� �ҷ��� firstname�� fn���� �ٽ� �����Ѵ�.
	- �׷��� ��� �ʱ��� ����Ʈ ������ ����ϸ� string ���� �����ڸ� ����Ͽ� firstname�� fn���� �ʱ�ȭ�ϴ� �� �ܰ踦 �������ش�.
*/



void TableTennisPlayer::Name() const
{
	cout << lastname << ", " << firstname;
}

