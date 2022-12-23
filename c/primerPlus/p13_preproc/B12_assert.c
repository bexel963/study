#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(void)
{
	double x, y, z;

	puts("두 수를 입력하시오(끝내려면 0 0): ");
	while (scanf("%lf %lf", &x, &y) == 2 && (x != 0 || y != 0))
	{
		z = x * x - y * y;
		assert(z >= 0);
		printf("제곱근: %f\n", sqrt(z));
		puts("다음 두 수를 입력하시오:");
	}

	puts("종료");


	return 0;
}