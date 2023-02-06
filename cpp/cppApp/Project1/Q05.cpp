#include <iostream>

using namespace std;
double change(double);

int main()
{
	cout << "섭씨 온도를 입력하고 Enter 키를 누르십시오: ";
	double tempC;
	cin >> tempC;

	cout << "섭씨 " << tempC << "도는 화씨로 " << change(tempC) << "도 입니다." << endl;

	return 0;
}

double change(double temp)
{
	return 1.8 * temp + 32.0;
}