#include <stdio.h>

int main(void)
{
	long num;
	long sum = 0L;
	_Bool input_is_good;

	printf("���� ���� ���� �ϳ� �Է�!");
	printf("(�������� q): ");
	input_is_good = (scanf("%ld", &num) == 1);
	while (input_is_good)
	{
		sum += num;
		printf("���� ���� �Է�!(�������� q): ");
		input_is_good = scanf("%ld", &num);
	}
	printf("�Էµ� �������� ��: %ld\n", sum);

	return 0;

}