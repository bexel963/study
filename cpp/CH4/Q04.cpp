#include <iostream>
#include <string>

using namespace std;

int main()
{
	string firstName;
	string lastName;
	string fullName;

	cout << "�۽�Ʈ ����(�̸�)�� �Է��Ͻÿ�: ";
	getline(cin, firstName);
	cout << "��Ʈ ����(��)�� �Է��Ͻÿ�: ";
	getline(cin, lastName);

	fullName = lastName + ", " + firstName;
	
	cout << "�ϳ��� ���ڿ��� �����: " << fullName << endl;

	return 0;
}