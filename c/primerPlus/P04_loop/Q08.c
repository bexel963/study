#include <stdio.h>

int main(void)
{
	float f1, f2;
	float mul, sub;

	printf("소수점 수 두 개 입력(끝내려면 문자 입력): \n");
	while (scanf("%f %f", &f1, &f2))
	{
		sub = f1 - f2;
		mul = f1 * f2;

		printf("%.2f\n", sub / mul);
		printf("소수점 수 두 개 입력(끝내려면 문자 입력): \n");
	}
	puts("종료!");

	return 0;

}