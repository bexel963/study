#include <iostream>

double change(double);

int main()
{
	using namespace std;

	cout << "���� ���� �Է��ϰ� Enter Ű�� �����ʽÿ�: ";
	double lightYear;
	cin >> lightYear;

	cout << lightYear << "������ " << change(lightYear) << "õ�� �����Դϴ�." << endl;

	return 0;
}

double change(double year)
{
	return year * 63240;
}