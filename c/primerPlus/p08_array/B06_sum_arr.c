#include <stdio.h>
#define SIZE 10

// 4���� ������ Ÿ���� ���� �ǹ��̴�.
int sum(int ar[], int n);
//int sum(int*, int);
//int sum(int *ar, int n);
//int sum(int[], int);

int main(void)
{
	int marbles[SIZE] = { 20,10,5,39,4,16,19,26,31,20 };
	long answer;

	answer = sum(marbles, SIZE);

	printf("������ ��ü ������: %ld���Դϴ�.\n", answer);
	printf("marbles�� ũ��� %zd����Ʈ �Դϴ�.\n", sizeof marbles);

	return 0;
}

//int sum(int *ar, int n)	// �Ʒ��� �ڵ�� ����
int sum(int ar[], int n)
{
	int total = 0;

	for (int i = 0; i < SIZE; i++)
	{
		total += *(ar + i);	// �Ʒ��� �ڵ�� ����
		//total += ar[i];
	}
	printf("ar�� ũ��� %zd����Ʈ�Դϴ�.\n", sizeof ar);

	return total;
}