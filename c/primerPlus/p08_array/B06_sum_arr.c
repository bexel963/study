#include <stdio.h>
#define SIZE 10

// 4가지 프로토 타입은 같은 의미이다.
int sum(int ar[], int n);
//int sum(int*, int);
//int sum(int *ar, int n);
//int sum(int[], int);

int main(void)
{
	int marbles[SIZE] = { 20,10,5,39,4,16,19,26,31,20 };
	long answer;

	answer = sum(marbles, SIZE);

	printf("구슬의 전체 개수는: %ld개입니다.\n", answer);
	printf("marbles의 크기는 %zd바이트 입니다.\n", sizeof marbles);

	return 0;
}

//int sum(int *ar, int n)	// 아래줄 코드와 같음
int sum(int ar[], int n)
{
	int total = 0;

	for (int i = 0; i < SIZE; i++)
	{
		total += *(ar + i);	// 아래줄 코드와 같음
		//total += ar[i];
	}
	printf("ar의 크기는 %zd바이트입니다.\n", sizeof ar);

	return total;
}