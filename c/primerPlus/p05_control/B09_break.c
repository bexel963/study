#include <stdio.h>

int main(void)
{
	float length, width;

	printf("�簢���� ���̸� �Է��Ͻÿ�:\n");

	while (scanf("%f", &length) == 1)
	{
		printf("���� = %0.2f:\n", length);
		printf("�ʺ� �Է��Ͻÿ�:\n");
		if (scanf("%f", &width) != 1)
			break;
		printf("�ʺ� = %0.2f:\n", width);
		printf("���� = %.2f:\n", (double)length * width);
		printf("�簢���� ���̸� �Է��Ͻÿ�:\n");
	}
	printf("����\n");

	return 0;
}