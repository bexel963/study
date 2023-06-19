#include <iostream>
#include "parent.h"

int main()
{
	using std::cout;
	TableTennisPlayer player1("Chuck", "Blizzard", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);
	/*
		- ������ ���𿡼� �Ű��������� Ÿ���� const string& ������ ���� �Ǿ��ִ�.
		  �̰��� �߸� ����� �ڷ������ڸ�, ǥ�� stringŬ������ 12���� StringŬ������ ����ϰ� const char* ���� �Ű������� ���� �����ڸ� ������ �ִ�.
		  �׸��� �� �����ڴ� C��Ÿ�� string���� �ʱ�ȭ�� string ��ü�� �����ϱ� ���� �ڵ����� ���ȴ�.
		  ��, TableTennisPlayer �����ڿ� ���� �Ű������� C��Ÿ�� string �̳� string ��ü �� ���� �� � ���� ����ص� �����ϴ�.
		- string ��ü�� const string& ���� �Ű������� ���� string �����ڸ� �ҷ�����, C��Ÿ�� string�� const char* ���� �Ű������� ���� string �����ڸ� �ҷ��´�.
	*/

	player1.Name();
	if (player1.HasTable())
		cout << ": Ź���밡 �ִ�.\n";
	else
		cout << ": Ź���밡 ����.\n";
	player2.Name();
	if (player2.HasTable())
		cout << ": Ź���밡 �ִ�.\n";
	else
		cout << ": Ź���밡 ����.\n";

	return 0;
}