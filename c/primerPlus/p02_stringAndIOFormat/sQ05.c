#include <stdio.h>

int main(void)
{
	float speed;
	float size;

	printf("�ٿ�ε� �ӵ��� ���� ũ�� �Է�: ");
	scanf("%f %f", &speed, &size);

	printf("�ʴ� %.2f �ް���Ʈ, %.2f �ް�����Ʈ ������\n%.2f�ʿ� �ٿ�ε��Ѵ�.\n\n", speed, size, size/(speed/8));

	return 0;
}