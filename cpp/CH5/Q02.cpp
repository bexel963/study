#include <iostream>
#include <array>

using namespace std;

const int SIZE = 101;
int main()
{
	array<long double, SIZE> factorial;
	
	factorial[0] = factorial[1] = 1;

	for (int i = 2; i < SIZE; i++)
		factorial[i] = i * factorial[i - 1];

	for (int i = 1; i < SIZE; i++)
		cout << i << "! = " << factorial[i] << endl;

	return 0;
}