#include <stdio.h>

float getCubic(float);

int main(void)
{
	float input;
	printf("�Ҽ� �ϳ� �Է�: ");
	scanf("%f", &input);
	
	printf("%.2f\n\n", getCubic(input));

	return 0;
}

float getCubic(float f)
{
	return f * f * f;
}