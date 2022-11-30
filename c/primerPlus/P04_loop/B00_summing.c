#include <stdio.h>

int main(void)
{
	long num;
	long sum = 0L;
	int status;

	printf("합을 구할 정수 하나 입력!");
	printf("(끝내려면 q): ");
	
	status = scanf("%ld", &num);
	while (status == 1)
	{
		sum += num;
		printf("다음 정수 입력!(끝내려면 q): ");
		status = scanf("%ld", &num);
	}
	printf("입력된 정수들의 합: %ld\n", sum);

	return 0;
}