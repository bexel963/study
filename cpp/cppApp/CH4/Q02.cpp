#include <iostream>
#include <string>

using namespace std;

int main()
{
	string firstName, lastName;
	char grade;
	int age;

	cout << "���� �۽�Ʈ ����(�̸�): ";
	getline(cin, firstName);
	cout << "��Ʈ ����(��): ";
	cin >> lastName;
	cout << "�л��� ���ϴ� ����: ";
	cin >> grade;
	cout << "����: ";
	cin >> age;

	if (grade == 'A')
		grade = 'B';
	else if (grade == 'B')
		grade = 'C';
	else
		grade = 'D';

	cout << "=====���=====" << endl;
	cout << "����: " << lastName << ", " << firstName << endl;
	cout << "����: " << grade << endl;
	cout << "����: " << age << endl;
}