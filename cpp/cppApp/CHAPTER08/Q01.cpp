#include <iostream>

using namespace std;

void printStr(const char*, int n = 1);

int main()
{
	const char* str = "abcdefghijklmnopqrstuvwxyz";

	printStr(str);
	cout << "------------------------\n";
	printStr(str, 2);
	cout << "------------------------\n";
	printStr(str, 3);
	cout << "------------------------\n";
	printStr(str, 4);
	cout << "------------------------\n";
	printStr(str, 5);
	cout << "------------------------\n";

	return 0;
}

void printStr(const char* str, int n)
{
	if (n <= 0)
		return;

	printStr(str, --n);
	cout << str << endl;
}