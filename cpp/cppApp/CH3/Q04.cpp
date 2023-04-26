#include <iostream>

using namespace std;

int perHour = 24;
int perMin = 60;
int perSec = 60;

int main()
{
	long inputSec, sec;
	int day, hour, min;

	cout << "초 수를 입력하시오: ";
	cin >> inputSec;

	min = inputSec / perSec;
	sec = inputSec % perSec;

	hour = min / perMin;
	min %= perMin;

	day = hour / perHour;
	hour %= perHour;
	
	cout << inputSec << "초 = " << day << "일, " << hour << "시간, " << min << "분, " << sec << "초" << endl;

	return 0;
}