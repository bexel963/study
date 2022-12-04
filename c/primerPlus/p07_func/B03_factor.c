#include <stdio.h>
long fact(int n);
long rfact(int n);

int main(void)
{
	int num;
	
	printf("이 프로그램은 계승을 계산합니다.\n");
	printf("0~12 범위의 한 값을 입력하시오(끝내려면 q):\n");
	while (scanf("%d", &num) == 1)
	{
		if (num < 0)
			printf("음수는 계승이 정의되지 않습니다.\n");
		else if (num > 12)
			printf("13미만을 입력하시오.\n");
		else
		{
			printf("루프: %d! = %ld\n", num, fact(num));
			printf("재귀: %d! = %ld\n", num, rfact(num));
		}
		printf("0~12 범위의 한 값을 입력하시오(끝내려면 q): \n");
	}
	printf("종료!\n");

	return 0;
}

long fact(int n)
{
	long ans;

	for (ans = 1; n > 1; n--)
		ans *= n;

	return ans;
}
long rfact(int n)
{
	long ans;

	if (n > 0)
		ans = n * rfact(n - 1);
	else
		ans = 1;

	return ans;
}