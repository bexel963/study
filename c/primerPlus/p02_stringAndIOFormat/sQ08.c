#include <stdio.h>
#define LITER 3.785
#define KILO 1.609

int main(void)
{
	float miles;
	float gallon;
	
	printf("주행거리(마일): ");
	scanf("%f", &miles);
	getchar();
	printf("소비한 휘발유의 양(갤런): ");
	scanf("%f", &gallon);

	printf("갤런당 마일 수: %.1f\n\n", miles / gallon);
	
	printf("%f / %f\n", (gallon * LITER), (miles * KILO * 100));
	printf("100킬로미터당 리터 수: %.1f\n\n", (gallon * LITER) / (miles * KILO * 100));

	return 0;

}