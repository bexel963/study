#include <iostream>
#include <string>

using namespace std;

struct TCL
{
	string cooName;
	float diameter;
	float weight;
};

int main()
{
	TCL* p = new TCL;


	cout << "������ ���� �Է�: ";
	(cin >> p->diameter).get();
	cout << "ȸ��� �Է�: ";
	getline(cin, p->cooName);
	cout << "������ �߷� �Է�: ";
	cin >> p->weight;

	cout << "=====���=====\n";
	cout << "ȸ���: " << p->cooName << endl;
	cout << "���� ����: " << p->diameter << endl;
	cout << "���� �߷�: " << p->weight << endl;

	return 0;
}