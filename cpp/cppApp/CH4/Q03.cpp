#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 20;

int main()
{
	char firstName[SIZE];
	char lastName[SIZE];
	char fullName[SIZE];
	int length;

	cout << "�۽�Ʈ ����(�̸�)�� �Է��Ͻÿ�: ";
	cin.getline(firstName, SIZE);
	cout << "��Ʈ ����(��)�� �Է��Ͻÿ�: ";
	cin.getline(lastName, SIZE);

	strcpy(fullName, lastName);
	length = strlen(fullName);
	strcat(fullName, ", ");
	strcat(fullName, firstName);

	cout << "�ϳ��� ���ڿ��� �����: " << fullName << endl;
	
	
	return 0;
}