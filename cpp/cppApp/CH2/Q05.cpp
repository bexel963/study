#include <iostream>

using namespace std;
double change(double);

int main()
{
	cout << "���� �µ��� �Է��ϰ� Enter Ű�� �����ʽÿ�: ";
	double tempC;
	cin >> tempC;

	cout << "���� " << tempC << "���� ȭ���� " << change(tempC) << "�� �Դϴ�." << endl;

	return 0;
}

double change(double temp)
{
	return 1.8 * temp + 32.0;
}