#include <stdio.h>

int main(void)
{
	int operand1;
	const int operand2;

	puts("�� ���α׷��� ��ⷯ��(�� ���� ���� ������)�� ���ϴ� ���α׷��̴�.");
	printf("�� ��° �ǿ����ڷ� ������ ������ �Է��Ͻÿ�.: ");
	scanf("%d", &operand2);
	printf("���� ù ��° �ǿ����ڸ� �Է��Ͻÿ�.: ");
	scanf("%d", &operand1);
	
	while (1)
	{
		printf("%d %% %d = %d\n", operand1, operand2, operand1 % operand2);
		
		printf("ù ��° �ǿ�����(<=0 �̸� ����)�� ���� ���� �Է��Ͻÿ�: ");
		scanf("%d", &operand1);
		
		if (operand1 <= 0)
			break;
	}

	puts("����~~");

	return 0;
}