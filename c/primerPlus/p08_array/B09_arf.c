#include <stdio.h>
#define SIZE 5
void show_array(const double ar[], int n);
void mult_array(double ar[], int n, double mult);

int main(void)
{
	double dip[SIZE] = { 20.0, 17.66, 8.2, 15.3, 22.22 };
	
	printf("원래의 dip 배열: \n");
	show_array(dip, SIZE);
	mult_array(dip, SIZE, 2.5);
	printf("mult_array() 호출 후의 dip 배열: \n");
	show_array(dip, SIZE);

	return 0;
}

void show_array(const double* ar, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%8.3f ", *(ar+1));
	}
	putchar('\n');
}

void mult_array(double* ar, int n, double mult)
{
	for (int i = 0; i < n; i++)
	{
		ar[i] *= mult;
	}
	return 0;
}