#include <iostream>

using namespace std;

const int SIZE = 20;

int main()
{
	char firstName[SIZE];
	char lastName[SIZE];
	char grade;
	int age;

	cout << "���� �۽�Ʈ ����(�̸�): ";
	cin.getline(firstName, SIZE);
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

	return 0;
}