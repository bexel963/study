#include <iostream>
#include <climits>

int main()
{
	using namespace std;
	
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	cout << "int는 " << sizeof(int) << "바이트이다." << endl;
	cout << "short는 " << sizeof(short) << "바이트이다." << endl;
	cout << "long는 " << sizeof(long) << "바이트이다." << endl;
	cout << "long long는 " << sizeof(long long) << "바이트이다." << endl;
	cout << endl;

	cout << "최대값" << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl;
	cout << "long long: " << n_llong << endl << endl;
	cout << "int의 최솟값: " << INT_MIN << endl;
	cout << "바이트 당 비트수 = " << CHAR_BIT << endl;

	return 0;
}