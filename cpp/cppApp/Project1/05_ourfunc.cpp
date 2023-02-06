#include <iostream>
void simon(int);

int main()
{
	using namespace std;
	simon(3);

	cout << "정수를 하나 고로시오: ";
	int count;
	cin >> count;
	simon(count);

	cout << "끝!" << endl;

	return 0;
}

void simon(int n)
{
	using namespace std;
	cout << "Simon왈, 발가락을 " << n << "번 두드려라." << endl;
}