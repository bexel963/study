#include <iostream>

const int ArSize = 20;

int main()
{
	using namespace std;

	char name[ArSize];

	cout << "영문 이름을 입력하십시오: ";
	cin >> name;
	cout << "귀하의 영문 이름을 한 줄에 한 자씩\n ASCII 코드와 함께 표시하면 이렇습니다.\n";

	int i = 0;
	while (name[i] != '\0')
	{
		cout << name[i] << ": " << (int)name[i] << endl;
		i++;
	}

	return 0;
}