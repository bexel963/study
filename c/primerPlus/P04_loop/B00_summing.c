#include <stdio.h>

int main(void)
{
	long num;
	long sum = 0L;
	int status;

	printf("���� ���� ���� �ϳ� �Է�!");
	printf("(�������� q): ");
	
	status = scanf("%ld", &num);
	while (status == 1)
	{
		sum += num;
		printf("���� ���� �Է�!(�������� q): ");
		status = scanf("%ld", &num);
	}
	printf("�Էµ� �������� ��: %ld\n", sum);

	return 0;
}