#include <iostream>

using namespace std;

const int SIZE = 10;

int main()
{
	double arr[SIZE];
	int cnt = 0;
	double sum = 0;
	double avg = 0;
	int overAvgCnt = 0;

	while ((cnt < 10) && (cin >> arr[cnt]))
	{
		sum += arr[cnt];		
		cnt++;
	}
	avg = sum / cnt;

	for (int i = 0; i < cnt; i++)
	{
		if (arr[i] > avg)
			overAvgCnt++;
	}

	cout << "�Է��� ����: " << cnt << endl;
	cout << "�迭 ����: ";
	for(int i=0 ; i<cnt ; i++)
		cout << arr[i] << " ";
	cout << endl;

	cout << "�� ��: " << sum << endl;
	cout << "���: " << avg << endl;
	cout << "��պ��� ū ������ ����: " << overAvgCnt << endl;

	return 0;
}