#include <iostream>

using namespace std;
const int SIZE = 10;

int input(int*);
void scorePrint(int*, int);
double getAvg(int*, int);

int main()
{
	int score[SIZE];

	idx = input(score);
	cout << "idx = " << idx << endl;
	scorePrint(score, idx);
	
	cout << "평균: " << getAvg(score, idx);
	

	return 0;
}

int input(int* arr)
{
	int cnt = 0;
	
	cout << "스코어를 최대 10개까지 입력(10개 전에 입력을 마치려면 문자 입력): ";
	while ((cnt<SIZE && cin>>arr[cnt]))
	{
		cnt++;
	}

	return cnt;
}

void scorePrint(int* arr, int idx)
{
	cout << "<스코어 리스트>" << endl;
	for (int i = 0; i < idx; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

double getAvg(int* arr, int idx)
{
	int sum = 0;
	for (int i = 0; i < idx; i++)
		sum += arr[i];
	
	return sum / (double)idx;
}