#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	double* ptd;
	int max;
	int number;
	int i = 0;

	puts("double�� ���� �ִ� �� ���� �Է��� �����Դϱ�?");
	if (scanf("%d", &max) != 1)
	{
		puts("���ڰ� ��Ȯ�ϰ� �Էµ��� �ʾҽ��ϴ�. --�ȳ�!");
		exit(EXIT_FAILURE);
	}
	ptd = (double*)malloc(max * sizeof(double));
	if (ptd == NULL)
	{
		puts("�޸� �Ҵ翡 �����߽��ϴ�. �̾��մϴ�.");
		exit(EXIT_FAILURE);
	}
	puts("������ �Է��Ͻÿ�(�������� q): ");
	while (i < max && scanf("%lf", &ptd[i]) == 1)
		i++;
	printf("�Է��Ͻ� %d���� ������ ������ �����ϴ�.\n", number = i);
	for (i = 0; i < number; i++)
	{
		printf("%7.2f", ptd[i]);
		if (i % 7 == 6)
			putchar('\n');
	}
	puts("����.");
	free(ptd);

	return 0;
}