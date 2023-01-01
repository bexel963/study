#include <stdio.h>
#define SIZE 8

int main(void)
{
	double arr[SIZE];
	double accumulation[SIZE];
	double sum = 0;

	printf("소수점 수 8개 입력: ");
	for (int i = 0; i < SIZE; i++)
	{
		scanf("%lf", &arr[i]);
		sum += arr[i];
		accumulation[i] = sum;
	}
	
	for (int i = 0; i < SIZE; i++)
	{
		printf("%3.2f ", arr[i]);		
	}	
	putchar('\n');
	for (int i = 0; i < SIZE; i++)
	{
		printf("%3.2f ", accumulation[i]);
	}
	putchar('\n');
	putchar('\n');
	return 0;
}