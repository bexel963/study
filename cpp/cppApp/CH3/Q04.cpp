#include <iostream>

using namespace std;

int perHour = 24;
int perMin = 60;
int perSec = 60;

int main()
{
	long inputSec, sec;
	int day, hour, min;

	cout << "�� ���� �Է��Ͻÿ�: ";
	cin >> inputSec;

	min = inputSec / perSec;
	sec = inputSec % perSec;

	hour = min / perMin;
	min %= perMin;

	day = hour / perHour;
	hour %= perHour;
	
	cout << inputSec << "�� = " << day << "��, " << hour << "�ð�, " << min << "��, " << sec << "��" << endl;

	return 0;
}