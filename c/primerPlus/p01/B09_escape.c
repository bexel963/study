#include <stdio.h>

int main(void)
{
	float salary;

	printf("\a원하는 월급 액수를 입력하시오: ");
	printf("$_______\b\b\b\b\b\b\b");
	scanf("%f", &salary);
	printf("\n\t월 $%.2f이면 연봉으로 $%.2f입니다.", salary, salary * 12.0);
	printf("\r우와!\n");

	return 0;
}