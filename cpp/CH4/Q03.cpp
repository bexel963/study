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

	cout << "퍼스트 네임(이름)을 입력하시오: ";
	cin.getline(firstName, SIZE);
	cout << "라스트 네임(성)을 입력하시오: ";
	cin.getline(lastName, SIZE);

	strcpy(fullName, lastName);
	length = strlen(fullName);
	strcat(fullName, ", ");
	strcat(fullName, firstName);

	cout << "하나의 문자열로 만들면: " << fullName << endl;
	
	
	return 0;
}