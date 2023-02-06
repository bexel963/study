#include <stdio.h>
#define ROWS 3
#define COLS 5

void print(double(*)[COLS]);
void copy_arr(double(*)[COLS], double(*)[5]);

int main(void)
{
	double arr2D[ROWS][COLS] = {
		{ 1.1, 2.2, 3.3, 4.4, 5.5 },
		{ 6.6, 7.7, 8.8, 9.9, 10.0},
		{ 11.1, 12.2, 13.3, 14.4, 15.5 }
	};

	double copy2D[ROWS][COLS] = { 0 };

	fputs("원 본: \n", stdout);
	print(arr2D);
	putchar('\n');

	copy_arr(arr2D, copy2D);

	fputs("복사본: \n", stdout);
	print(copy2D);
}

void copy_arr(double(*arr)[COLS], double(*copy)[COLS])
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			copy[i][j] = arr[i][j];
}
void print(double(*arr)[COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			printf("%5.1f ", arr[i][j]);
		putchar('\n');
	}
}