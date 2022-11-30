#include <stdio.h>

int main(void)
{
	unsigned width, precision;
	int number = 256;
	double weight = 242.5;

	printf("필드 너비 입력: ");
	scanf("%d", &width);
	printf("Number:%*d: \n", width, number);

	printf("필드 너비와 정밀도 입력: ");
	scanf("%d %d", &width, &precision);
	printf("Weight =%*.*f\n", width, precision, weight);
	printf("종료\n");

	return 0;
}