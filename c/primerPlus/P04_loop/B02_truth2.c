#include <stdio.h>

int main(void)
{
	long num;
	long sum = 0L;
	_Bool input_is_good;

	printf("합을 구할 정수 하나 입력!");
	printf("(끝내려면 q): ");
	input_is_good = (scanf("%ld", &num) == 1);
	while (input_is_good)
	{
		sum += num;
		printf("다음 정수 입력!(끝내려면 q): ");
		input_is_good = scanf("%ld", &num);
	}
	printf("입력된 정수들의 합: %ld\n", sum);

	return 0;

}