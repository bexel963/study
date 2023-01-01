#include <stdio.h>

int main(void)
{
	int operand1;
	const int operand2;

	puts("이 프로그램은 모듈러스(두 수를 나눈 나머지)를 구하는 프로그램이다.");
	printf("두 번째 피연산자로 제공할 정수를 입력하시오.: ");
	scanf("%d", &operand2);
	printf("이제 첫 번째 피연산자를 입력하시오.: ");
	scanf("%d", &operand1);
	
	while (1)
	{
		printf("%d %% %d = %d\n", operand1, operand2, operand1 % operand2);
		
		printf("첫 번째 피연산자(<=0 이면 종료)용 다음 수를 입력하시오: ");
		scanf("%d", &operand1);
		
		if (operand1 <= 0)
			break;
	}

	puts("종료~~");

	return 0;
}