#include <iostream>

using namespace std;

double getHavg(int, int);

int main()
{
	int x, y;
	
	while (true)
	{
		cout << "두 수를 한 쌍으로 입력 (x y): ";
		cin >> x;
		cin >> y;
		if (x == 0 || y == 0)
			break;
		
		cout << "입력한 두 수의 조화평균: " << getHavg(x, y) << endl;
	}

	return 0;
}

double getHavg(int x, int y)
{
	return 2.0 * x * y / (x + y);
}