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
	
	cout << "���: " << getAvg(score, idx);
	

	return 0;
}

int input(int* arr)
{
	int cnt = 0;
	
	cout << "���ھ �ִ� 10������ �Է�(10�� ���� �Է��� ��ġ���� ���� �Է�): ";
	while ((cnt<SIZE && cin>>arr[cnt]))
	{
		cnt++;
	}

	return cnt;
}

void scorePrint(int* arr, int idx)
{
	cout << "<���ھ� ����Ʈ>" << endl;
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