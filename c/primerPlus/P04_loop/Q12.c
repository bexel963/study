#include <stdio.h>

int main(void)
{
	int constant;
	float sum1 = 0, sum2 = 0;
	int result;
	int negative = 1;

	printf("항 수 입력(끝내려면 0 또는 음수 입력): ");
	result = scanf("%d", &constant);

	while (result)
	{
		if (constant <= 0)
			break;
		int i;
		float denominator;
		for (i = 0, denominator=1.0; i < constant; i++, denominator++)
		{
			sum1 += 1.0 / denominator;
		}
		for (i = 0, denominator = 1.0; i < constant; i++, denominator++)
		{
			sum2 += 1.0 / denominator * negative;
			negative *= -1;
		}
		
		printf("%d항 까지의 합(sum1): %10.4f\n", constant, sum1);
		printf("%d항 까지의 합(sum2): %10.4f\n", constant, sum2);

		printf("항 수 입력(끝내려면 0 또는 음수 입력): ");
		result = scanf("%d", &constant);
	}
	puts("종료~");
	return 0;
}