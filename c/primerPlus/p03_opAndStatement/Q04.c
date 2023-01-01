#include <stdio.h>
#define INCH 2.54		// 1inch = 2.54cm
#define FEET 30.48		// 1feet = 30.48

int main(void)
{
	float height;
	float inch;
	int feet;

	printf("센티미터 단위로 키를 입력하시오(끝내려면 <=0): ");
	scanf("%f", &height);
	while (1)
	{
		if (height <= 0)
			break;
		inch = height / INCH;
		feet = (int)(height / FEET);
		printf("%.1f센티미터는 %d피트, %.1f인치 입니다.\n", height, feet, inch);

		printf("센티미터 단위로 키를 입력하시오 (끝내려면 <=0): ");
		scanf("%f", &height);
	}
	
	puts("안녕!");

	return 0;
}