#include <iostream>

using namespace std;

void print(int, int);

int main()
{
	int hour, min;

	cout << "�ð� ���� �Է��Ͻÿ�: ";
	cin >> hour;
	cout << "�� ���� �Է��Ͻÿ�: ";
	cin >> min;

	print(hour, min);

	return 0;
}

void print(int hour, int min)
{
	cout << "�ð�: " << hour << ":" << min << endl;
}