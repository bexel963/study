#include <stdio.h>

float getCubic(float);

int main(void)
{
	float input;
	printf("소수 하나 입력: ");
	scanf("%f", &input);
	
	printf("%.2f\n\n", getCubic(input));

	return 0;
}

float getCubic(float f)
{
	return f * f * f;
}