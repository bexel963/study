#include <iostream>

int main()
{
	using namespace std;

	cout << "거리 입력(마일): ";
	double miles;
	cin >> miles;
	
	cout << miles << "마일은 " << miles * 1.60934 << "킬로미터" << endl;

	return 0;
}