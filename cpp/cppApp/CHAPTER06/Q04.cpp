#include <iostream>
#include <cstring>

using namespace std;
const int strSize = 20;
const int users = 5;

struct Bop {
	char fullName[strSize];
	char title[strSize];
	char bopName[strSize];
	int preference;
};

void init(Bop*);
void menu();
void setting(Bop*, int);
void print(Bop*);

int main()
{
	Bop bop[users];
	char input;

	init(bop);
	menu();

	while ((input = cin.get()) && input != 'q')
	{
		cin.get();
		switch (input)
		{
		case 'a':
			setting(bop, 0);
			break;
		case 'b':
			setting(bop, 1);
			break;
		case 'c':
			setting(bop, 2);
			break;
		case 'd':
			break;
		default:
			cout << "a, b, c, d �� �ϳ��� �Է��ϼ��� (�������� q): ";
			continue;
		}
		
		print(bop);
	}

	return 0;
}

void print(Bop* bop)
{
	int n = 0;
	n = bop[0].preference;
	
	if (n == 0)
	{
		for (int i = 0; i < users; i++)
			cout << bop[i].fullName << endl;
	}
	else if (n == 1)
	{
		for (int i = 0; i < users; i++)
			cout << bop[i].title << endl;	
	}
	else
	{
		for (int i = 0; i < users; i++)
			cout << bop[i].bopName << endl;
	}
	
}
void setting(Bop* bop, int n)
{
	for (int i = 0; i < users; i++)
		bop[i].preference = n;
}
void menu()
{
	cout << "Benevolent Order of Programmers" << endl;
	cout << "a. �Ǹ����� ����\t\tb. �������� ����\nc. Bop ���̵�� ����\t\td. ȸ���� ������ ������ ����\nq. ����\n";
	cout << "���ϴ� ���� �����Ͻʽÿ�: ";
}
void init(Bop* bop)
{
	char tmp[3];
	for (int i = 0; i < users; i++)
	{
		tmp[0] = (i + 1) + '0';
		tmp[1] = ')';
		tmp[2] = '\0';
		strcpy(bop[i].fullName, "�Ǹ�(");
		strcat(&bop[i].fullName[strlen(bop[i].fullName)], tmp);

		strcpy(bop[i].title, "����(");
		strcat(&bop[i].title[strlen(bop[i].title)], tmp);

		strcpy(bop[i].bopName, "���̵�(");
		strcat(&bop[i].bopName[strlen(bop[i].bopName)], tmp);
		
		bop[i].preference = 2;
	}
}