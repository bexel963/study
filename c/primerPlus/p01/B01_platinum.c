#include <stdio.h>

int main(void)
{
	float weight;
	float value;

	printf("����� �����Ը� �÷�Ƽ�� ��ġ�� ����ϸ� �󸶳� �������?\n");
	printf("��� �ѹ� ����� ���ô�.\n");
	printf("�����Ը� �Ŀ�� ������ �Է��Ͻÿ�: ");
	
	scanf("%f", &weight);

	// 1�Ŀ�忡 �ش��ϴ� �½� ��: 14.5833
	// �½��� �ͱݼӿ� ���̴� ��������, �Ŀ��� �ͱݼ�, ����, ��ǰ�� ������ ��� �Ϳ� ���̴� ��������
	value = 1700.0 * weight * 14.5833;
	printf("\n����� �����Ը� �÷�Ƽ�� ��ġ�� ����ϸ� $%.2f�Դϴ�.\n", value);
	printf("����� ������ �� ���� ��ġ�� �����ϴ�. �÷�Ƽ�� ������ ��������, \n");
	printf("��ġ�� �����ϱ� ���� �Ļ緮�� �÷��� �մϴ�.\n");

	getchar();	// scanf()���� �Է��� ���๮�ڸ� �а�,
	getchar();	// ���α׷��� ���߰� �Է��� ��ٸ���.

	return 1;
}