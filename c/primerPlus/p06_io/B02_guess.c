#include <stdio.h>

int main(void)
{
	int guess = 1;

	printf("1���� 100���� ������ �ִ� �� ������ �����Ͻÿ�.\n");
	printf("���� ����������. �� ������ ������ y�� �����ϰ�, \n");
	printf("�� ������ Ʋ���� n���� �����Ͻÿ�.\n");
	printf("����� ������ ���� %d�Դϱ�?\n", guess);
	
	while (getchar() != 'y')
	{
		printf("�׷��� %d�Դϱ�?\n", ++guess);

		while ((getchar() != '\n'))
			continue;
	}
	printf("�װ� ����, ���� ���� �� �ִٰ� ���ݾƿ�!\n");

	return 0;
}