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
	
	puts("5���� �Ҽ��� ���� 3�� �Է� �Ͻÿ�:");
	while (cnt < ROWS)
	{
		inputArr(*(input + cnt));
		printf("%d�� �Է���.\n", cnt + 1);
		cnt++;
	}

	puts("\n<�� �࿡ ���� ���>");
	cnt = 0;
	while (cnt < ROWS)
	{
		printf("%d��: %5.1f\n", cnt + 1, avgOfRows(*(input+cnt), COLS));
		cnt++;
	}

	printf("\n��ü ������ ���: %5.1f\n", avgOfTot(input, ROWS));
	
	printf("\n��ü ���� �� ���� ū ��: %5.1f\n", getMax(input, ROWS));

	return 0;
}
void inputArr(double* arr)
{
	int result;
	while ((result = scanf("%lf %lf %lf %lf %lf", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]) != 5))
	{
		printf("�Ҽ� �� �� 5���� ��Ȯ�� �Է��ϼ���~~\n");
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