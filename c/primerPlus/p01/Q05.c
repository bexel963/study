/*
	1년은 약 3.156 x 10^7초에 해당한다.
	나이를 햇수로 입력 받아, 초단위로 출력
*/
#include <stdio.h>
#define SCND 3.156e7

int main(void)
{
	int age;

	printf("나이 입력: ");
	scanf("%d", &age);

	printf("나이: %d세, 초단위로 환산: %.4f", age, age * SCND);

	return 0;
}