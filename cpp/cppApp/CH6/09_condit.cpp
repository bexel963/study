#include <iostream>

int main()
{
	using namespace std;

	int a, b;
	cout << "두 개의 정수를 입력하십시오: ";
	cin >> a >> b;
	cout << "둘 중에서 더 큰 정수는 ";
	int c = a > b ? a : b;
	cout << c << "입니다.\n";

	return 0;
}