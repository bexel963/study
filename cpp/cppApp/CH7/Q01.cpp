#include <iostream>

using namespace std;

double getHavg(int, int);

int main()
{
	int x, y;
	
	while (true)
	{
		cout << "�� ���� �� ������ �Է� (x y): ";
		cin >> x;
		cin >> y;
		if (x == 0 || y == 0)
			break;
		
		cout << "�Է��� �� ���� ��ȭ���: " << getHavg(x, y) << endl;
	}

	return 0;
}

double getHavg(int x, int y)
{
	return 2.0 * x * y / (x + y);
}