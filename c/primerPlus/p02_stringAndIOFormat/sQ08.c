#include <stdio.h>
#define LITER 3.785
#define KILO 1.609

int main(void)
{
	float miles;
	float gallon;
	
	printf("����Ÿ�(����): ");
	scanf("%f", &miles);
	getchar();
	printf("�Һ��� �ֹ����� ��(����): ");
	scanf("%f", &gallon);

	printf("������ ���� ��: %.1f\n\n", miles / gallon);
	
	printf("%f / %f\n", (gallon * LITER), (miles * KILO * 100));
	printf("100ų�ι��ʹ� ���� ��: %.1f\n\n", (gallon * LITER) / (miles * KILO * 100));

	return 0;

}