#include <stdio.h>

void report_count();
void accumulate(int);

int count = 0;

int main(void)
{
	int value;
	register int i;

	printf("���� ������ �ϳ� �Է��Ͻÿ�(���·��� 0): ");
	while (scanf("%d", &value) == 1 && value > 0)
	{
		++count;
		for (i = value; i >= 0; i--)
		{
			accumulate(i);
		}
	}
	report_count();

	return 0;
}
void report_count()
{
	printf("������ ����� Ƚ��: %d\n", count);
}