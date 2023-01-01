/*
	미국에서는 부피 단위로 pint를 사용한다.
	1pint는 2cups이고, 1cup은 8ounces, 1ounce는 2tablespoons, 1tablespoon은 3teaspoon이다.
	cup단위로 부피가 얼마인지 묻고 그것을 pints, ounces, tablespoons, teaspoons으로 환산하여 표시
	왜 이 경우 부동소수점형이 정수형보다 더 적합한지 설명....
*/
#include <stdio.h>

int main(void)
{
	float pint;	// 부피
	float cups;	
	float ounces;
	float tablespoons;
	float teaspoons;

	printf("부피 입력(cup단위): ");
	scanf("%f", &cups);

	pint = cups / 2;
	ounces = cups * 8;
	tablespoons = ounces * 2;
	teaspoons = tablespoons * 3;
	putchar('\n');

	printf("%.4f(pint)\n", pint);
	printf("%.4f(ounces)\n", ounces);
	printf("%.4f(tablespoons)\n", tablespoons);
	printf("%.4f(teaspoons)\n\n", teaspoons);

	return 0;
}