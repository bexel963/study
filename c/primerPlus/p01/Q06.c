/*
	�� ������ ������ �� 3.0 x 10^-23�׷��̴�.
	�� 1��Ʈ�� �� 950�׷��̴�.
	��Ʈ ������ ���� ���� �Է¹޾�, �� �ȿ� ��� �ִ� �� ������ ������ ���
*/
#include <stdio.h>
#define WEIGHT 3.0e-23
#define GRAM 950

int main(void)
{
	float mol;

	printf("���� �� �Է�(���� ����): ");
	scanf("%f", &mol);
	
	printf("�� ������ ����: %f\n\n", mol * GRAM / WEIGHT);

	return 0;
}