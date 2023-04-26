#include <iostream>

using namespace std;

const int len = 30;

struct Car
{
	char name[len];
	int year;
};

int main()
{
	int unit;

	cout << "관리할 차의 수 입력: ";
	(cin >> unit).get();

	Car* management = new Car[unit];

	cout << "===차 정보 입력===" << endl;
	for (int i = 0; i < unit; i++)
	{
		cout << "자동차 #" << i + 1 << ":" << endl;
		cout << "제작업체: ";
		cin.getline(management[i].name, len);
		cout << "제작년도: ";
		cin >> management[i].year;
		cin.get();
	}

	cout << "현재 귀하가 보유하고 있는 자동차 목록은 다음과 같습니다.\n";
	for (int i = 0; i < unit; i++)
		cout << management[i].year << "년형 " << management[i].name << endl;
}