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

	cout << "입력한 개수: " << cnt << endl;
	cout << "배열 내용: ";
	for(int i=0 ; i<cnt ; i++)
		cout << arr[i] << " ";
	cout << endl;

	cout << "총 합: " << sum << endl;
	cout << "평균: " << avg << endl;
	cout << "평균보다 큰 수들의 개수: " << overAvgCnt << endl;

	return 0;
}