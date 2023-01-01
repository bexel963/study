/*
	부동소수점 수를 하나 읽고 3가지 방법으로 출력한다.

		a. 소수점 표기
		b. 지수 표기
		c. p표기

		부동소수점 수를 입력하시오: 64.25
		고정소수점 표기: 64.250000
		지수 표기: 6.425000e+01
		p 표기: 0x1.01p+6
*/
#include <stdio.h>

int main(void)
{
	float f;

	printf("부동 소수점 수를 입력하시오: ");
	scanf("%f", &f);

	printf("고정 소수점 표기: %.6f\n", f);
	printf("지수 표기: %.6e\n", f);
	printf("p표기: %.2a\n", f);

	return 0;
}