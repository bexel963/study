#include <iostream>

using namespace std;

const int perMin = 60;
const int perSec = 3600;

int main()
{
	int angle, min, sec;

	cout << "������ ��, ��, �� ������ ���� �Է��ϼ���:\n";

	cout << "����, ������ �Է��Ͻÿ�: ";
	cin >> angle;
	cout << "������, �а��� �Է��Ͻÿ�: ";
	cin >> min;
	cout << "������, �ʰ��� �Է��Ͻÿ�: ";
	cin >> sec;	

	cout << angle << "��, " << min << "��, " << sec << "�� = " << (angle + sec * 1 / (float)perSec + min * 1 / (float)perMin) << "��" << endl;

	return 0;
}