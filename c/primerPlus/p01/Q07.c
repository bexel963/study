/*
	1인치는 2.54센티미터이다. 키를 센티미터 단위로 입력받아 인치 단위로 출력
*/
#include <stdio.h>
#define INCH 2.54

int main(void)
{
	float height;

	printf("키 입력(cm): ");
	scanf("%f", &height);

	printf("키: %.2f(%.2f)\n\n", height, height / INCH);

	return 0;
}