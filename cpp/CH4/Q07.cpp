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
	TCL pizza;
	
	cout << "ȸ��� �Է�: ";
	getline(cin, pizza.cooName);
	cout << "������ ���� �Է�: ";
	cin >> pizza.diameter;
	cout << "������ �߷� �Է�: ";
	cin >> pizza.weight;

	cout << "=====���=====\n";
	cout << "ȸ���: " << pizza.cooName << endl;
	cout << "���� ����: " << pizza.diameter << endl;
	cout << "���� �߷�: " << pizza.weight << endl;

	return 0;
}