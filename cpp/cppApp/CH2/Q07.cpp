#include <iostream>

using namespace std;

void print(int, int);

int main()
{
	int hour, min;

	cout << "시간 값을 입력하시오: ";
	cin >> hour;
	cout << "분 값을 입력하시오: ";
	cin >> min;

	print(hour, min);

	return 0;
}

void print(int hour, int min)
{
	cout << "시각: " << hour << ":" << min << endl;
}