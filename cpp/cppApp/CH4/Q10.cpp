#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 3> record;
	int cnt = 0;	
	int total = 0;

	while (cnt < 3)
	{
		cout << cnt+1 << "ȸ��: ";
		cin >> record[cnt];
		cnt++;
	}

	for (int i = 0; i < cnt; i++)
		total += record[i];

	cout << "�õ� Ƚ��: " << cnt << endl;
	cout << "���: " << total / (float)cnt << endl;

	return 0;
	
}