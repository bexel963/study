#include <iostream>

using namespace std;

const int len = 30;

struct Car
{
	char name[len];
	int year;
};

int main()
{
	int unit;

	cout << "������ ���� �� �Է�: ";
	(cin >> unit).get();

	Car* management = new Car[unit];

	cout << "===�� ���� �Է�===" << endl;
	for (int i = 0; i < unit; i++)
	{
		cout << "�ڵ��� #" << i + 1 << ":" << endl;
		cout << "���۾�ü: ";
		cin.getline(management[i].name, len);
		cout << "���۳⵵: ";
		cin >> management[i].year;
		cin.get();
	}

	cout << "���� ���ϰ� �����ϰ� �ִ� �ڵ��� ����� ������ �����ϴ�.\n";
	for (int i = 0; i < unit; i++)
		cout << management[i].year << "���� " << management[i].name << endl;
}