#include <iostream>
void countdown(int);

int main()
{
	countdown(4);

	return 0;
}

void countdown(int n)
{
	using namespace std;
	cout << "카운트 다운 ... " << n << " (n at " << &n << ")" << endl;
	if (n > 0)
		countdown(n - 1);

	cout << n << ": Kabbom!\n";
}