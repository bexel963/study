#include <iostream>

using namespace std;

const int SIZE = 20;

int main()
{
	char firstName[SIZE];
	char lastName[SIZE];
	char grade;
	int age;

	cout << "영문 퍼스트 네임(이름): ";
	cin.getline(firstName, SIZE);
	cout << "라스트 네임(성): ";
	cin >> lastName;
	cout << "학생이 원하는 학점: ";
	cin >> grade;
	cout << "나이: ";
	cin >> age;

	if (grade == 'A')
		grade = 'B';
	else if (grade == 'B')
		grade = 'C';
	else
		grade = 'D';

	cout << "=====출력=====" << endl;
	cout << "성명: " << lastName << ", " << firstName << endl;
	cout << "학점: " << grade << endl;
	cout << "나이: " << age << endl;

	return 0;
}