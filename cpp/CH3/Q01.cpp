#include <iostream>

int main()
{
	using namespace std;
	
	int height;
	const int m = 100;

	cout << "키 입력: ___cm\b\b\b\b\b";
	cin >> height;

	cout << height / m << "미터 " << height % m << "센티미터" << endl;

	return 0;
}