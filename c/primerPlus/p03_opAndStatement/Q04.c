#include <stdio.h>
#define INCH 2.54		// 1inch = 2.54cm
#define FEET 30.48		// 1feet = 30.48

int main(void)
{
	float height;
	float inch;
	int feet;

	printf("��Ƽ���� ������ Ű�� �Է��Ͻÿ�(�������� <=0): ");
	scanf("%f", &height);
	while (1)
	{
		if (height <= 0)
			break;
		inch = height / INCH;
		feet = (int)(height / FEET);
		printf("%.1f��Ƽ���ʹ� %d��Ʈ, %.1f��ġ �Դϴ�.\n", height, feet, inch);

		printf("��Ƽ���� ������ Ű�� �Է��Ͻÿ� (�������� <=0): ");
		scanf("%f", &height);
	}
	
	puts("�ȳ�!");

	return 0;
}