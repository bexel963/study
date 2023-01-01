/*
	물 분자의 질량은 약 3.0 x 10^-23그램이다.
	물 1쿼트는 약 950그램이다.
	쿼트 단위로 물의 양을 입력받아, 그 안에 들어 있는 물 분자의 개수를 출력
*/
#include <stdio.h>
#define WEIGHT 3.0e-23
#define GRAM 950

int main(void)
{
	float mol;

	printf("물의 양 입력(쿼터 단위): ");
	scanf("%f", &mol);
	
	printf("물 분자의 개수: %f\n\n", mol * GRAM / WEIGHT);

	return 0;
}