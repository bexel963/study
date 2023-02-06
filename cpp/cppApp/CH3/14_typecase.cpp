#include <iostream>

int main()
{
	using namespace std;

	int auks, bats, coots;

	auks = 19.99 + 11.99;

	bats = (int)19.99 + (int)11.99;
	coots = int(19.99) + int(11.99);
	cout << "바다오리 = " << auks << ", 박쥐 = " << bats << ", 검둥오리 = " << coots << endl;

	char ch = 'Z';
	cout << "코드 " << ch << "의 값은 " << int(ch) << endl;
	cout << "네, 코드 Z의 값은 " << static_cast<int>(ch) << endl;

	return 0;
}