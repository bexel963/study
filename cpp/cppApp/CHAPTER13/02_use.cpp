#include <iostream>
#include "child.h"

int main()
{
	using namespace std;
	
	TableTennisPlayer player1("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
	
	rplayer1.Name();
	if (rplayer1.HasTable())
		cout << ": Ź���밡 �ִ�.\n";
	else
		cout << ": Ź���밡 ����.\n";
	
	player1.Name();
	if (player1.HasTable())
		cout << ": Ź���밡 �ִ�.\n";
	else
		cout << ": Ź���밡 ����.\n";

	cout << "�̸�: ";
	rplayer1.Name();
	cout << "; ��ŷ: " << rplayer1.Rating() << endl;

	// TableTennisPlayer ��ü�� ����Ͽ� RatedPlayer�� �ʱ�ȭ �Ѵ�.
	RatedPlayer rplayer2(1212, player1);
	cout << "�̸�: ";
	rplayer2.Name();
	cout << "; ��ŷ: " << rplayer2.Rating() << endl;

	return 0;
}

/*
	- �Ļ� Ŭ������ ���� Ŭ������ ����
		1) �Ļ� Ŭ���� ��ü�� ���� Ŭ���� �޼������ private�� �ƴϸ� �װ͵��� ����� �� �ִ�.
		2) ���� Ŭ���� �����Ϳ� ���� Ŭ���� ������ ����� �������� ��ȯ�� ��� �Ļ� Ŭ���� ��ü�� ������ �� �ִ�.
			: �Ϲ������� C++�� �������� ���������� ���ԵǴ� ���������� ��ġ�� ���� �䱸������ ����� ��쿡�� �� ��Ģ�� ��ȭ�ȴ�.
			  �׷��� �̷��� ��Ģ ��ȭ�� �Ϲ� �������̴�. ��, �Ļ� Ŭ������ ������ �����Ϳ� ���� Ŭ������ ��ü�� �ּҸ� ������ �� ����.

	- RatedPlayer olaf1(1840, "Olaf", "Loaf", true);
	  TableTennisPlayer olaf2(olaf1);
		: olaf2�� �ʱ�ȭ�ϴ� �������� ��Ȯ�� ������ TableTennisPlayer(const RatedPlayer&); �̴�.
		  �׷��� ���� Ŭ���� ���� �̿� ���� �����ڸ� ������ �ʾҴ�.
		  �̷��� ���, �Ͻ����� ���� �����ڰ� �� ������ ����Ѵ�.
			-> TableTennisPlayer(const TableTennisPlayer&);	// �Ͻ����� ���� ������.
		  �� ���� �����ڴ� RatedPlayer ��ü olaf1 �ȿ� �Ĺ��� �ִ� TableTennisPlayer ��ü�� olaf2�� �ʱ�ȭ�Ѵ�.

	- RatedPlayer olaf1(1840, "Olaf", "Loaf", true);
	  TableTennisPlayer winner;
	  winner = olaf1;
		: �� ���, ���α׷��� ������ ���� �Ͻ����� �����ε� ���� �����ڸ� ���Կ� ����Ѵ�.
			-> TableTennisPlayer& operator=(const TableTennisPlayer&) const;
		  olaf1�� ���� Ŭ���� �κ��� winner�� ����ȴ�.
*/
