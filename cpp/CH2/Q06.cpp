#include <iostream>

double change(double);

int main()
{
	using namespace std;

	cout << "광년 수를 입력하고 Enter 키를 누르십시오: ";
	double lightYear;
	cin >> lightYear;

	cout << lightYear << "광년은 " << change(lightYear) << "천문 단위입니다." << endl;

	return 0;
}

double change(double year)
{
	return year * 63240;
}