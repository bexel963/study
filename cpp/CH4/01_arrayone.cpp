#include <iostream>

int main()
{
	using namespace std;

	int yams[3];
	yams[0] = 7;
	yams[1] = 8;
	yams[2] = 6;

	int yamcosts[3] = { 200, 300, 50 };

	cout << "���� �հ� = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << yams[1] << "���� ��� �ִ� ������ " << "���� " << yamcosts[1] << "���� �Դϴ�.\n";
	
	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1] + yams[2] * yamcosts[2];
	cout << "�� ������ �� ������ " << total << "�� �Դϴ�.\n";
	cout << "\nyams �迭�� ũ��� " << sizeof yams << "����Ʈ �Դϴ�.\n";
	cout << "���� �ϳ��� ũ��� " << sizeof yams[0] << "����Ʈ �Դϴ�.\n";

	return 0;
}