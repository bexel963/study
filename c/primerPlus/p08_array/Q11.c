#include <stdio.h>
#define ROWS 3
#define COLS 5

void print(double(*)[COLS], int);
void doubleArr(double(*)[COLS], int);

int main(void)
{
	double arr2D[ROWS][COLS] = {
		{ 1.1, 2.2, 3.3, 4.4, 5.5 },
		{ 6.6, 7.7, 8.8, 9.9, 10.0},
		{ 11.1, 12.2, 13.3, 14.4, 15.5 }
	};

	puts("초기 배열: ");
	print(arr2D, ROWS);

	doubleArr(arr2D, ROWS);
	puts("두 배 곱한 배열: ");
	print(arr2D, ROWS);
}

void doubleArr(double(*arr)[COLS], int rows)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < COLS; j++)
			arr[i][j] = arr[i][j] * 2;
}
void print(double(*arr)[COLS], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
			printf("%5.1f ", arr[i][j]);
		putchar('\n');
	}
}