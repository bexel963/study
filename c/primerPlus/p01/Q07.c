/*
	1��ġ�� 2.54��Ƽ�����̴�. Ű�� ��Ƽ���� ������ �Է¹޾� ��ġ ������ ���
*/
#include <stdio.h>
#define INCH 2.54

int main(void)
{
	float height;

	printf("Ű �Է�(cm): ");
	scanf("%f", &height);

	printf("Ű: %.2f(%.2f)\n\n", height, height / INCH);

	return 0;
}