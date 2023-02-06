#include <stdio.h>
#define ROWS 3
#define COLS 5

void inputArr(double*);
double avgOfRows(double*, int);
double avgOfTot(double(*)[COLS], int);
double getMax(double(*)[COLS], int);

int main(void)
{
	double input[ROWS][COLS] = { 0 };
	int cnt = 0;
	
	puts("5개의 소수점 수를 3번 입력 하시오:");
	while (cnt < ROWS)
	{
		inputArr(*(input + cnt));
		printf("%d행 입력함.\n", cnt + 1);
		cnt++;
	}

	puts("\n<각 행에 대한 평균>");
	cnt = 0;
	while (cnt < ROWS)
	{
		printf("%d행: %5.1f\n", cnt + 1, avgOfRows(*(input+cnt), COLS));
		cnt++;
	}

	printf("\n전체 값들의 평균: %5.1f\n", avgOfTot(input, ROWS));
	
	printf("\n전체 원소 중 가장 큰 값: %5.1f\n", getMax(input, ROWS));

	return 0;
}
void inputArr(double* arr)
{
	int result;
	while ((result = scanf("%lf %lf %lf %lf %lf", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]) != 5))
	{
		printf("소수 점 수 5개를 정확히 입력하세요~~\n");
		while (getchar() != '\n')
			continue;
	}
}
double avgOfRows(double* arr, int cols)
{
	double tot = 0;
	for (int i = 0; i < cols; i++)
		tot += arr[i];

	return tot / cols;
}

double avgOfTot(double(*arr)[COLS], int rows)
{
	double tot = 0;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < COLS; j++)
			tot += arr[i][j];

	return tot / (rows * COLS);
}

double getMax(double(*arr)[COLS], int rows)
{
	double max = **arr;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] > max)
				max = arr[i][j];
		}
	}

	return max;
}