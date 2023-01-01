#include <stdio.h>

int main(void)
{
	float height;

	printf("키 입력(inch): ");
	scanf("%f", &height);

	printf("Dabney 씨, 당신의 키는 %.3f 피트 입니다.\n\n", height);

	return 0;
}