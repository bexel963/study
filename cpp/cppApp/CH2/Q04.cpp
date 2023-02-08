#include <iostream>

int main()
{
	using namespace std;

	cout << "나이 입력: ";
	int age;
	cin >> age;

	cout << "당신의 나이를 월수로 나타낼 경우 " << age * 12 << "입니다." << endl;

	return 0;
}