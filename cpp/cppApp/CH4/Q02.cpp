#include <iostream>
#include <string>

using namespace std;

int main()
{
	string firstName, lastName;
	char grade;
	int age;

	cout << "영문 퍼스트 네임(이름): ";
	getline(cin, firstName);
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
}