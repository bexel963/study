#include <stdio.h>

int main(void)
{
	int min, max, sum = 0;
	int result;

	printf("������ ���Ѱ� ������ �Է��Ͻÿ�: ");
	result = scanf("%d %d", &min, &max);

	while (result)
	{
		if (min >= max)
			break;
		int tmp = min;
		for (min; min <= max; min++)
		{
			sum += min * min;
		}
		printf("%d���� %d����, �������� ���� %d\n", tmp*tmp, max*max, sum);
		printf("���� ���Ѱ� ������ �Է��Ͻÿ�: ");
		result = scanf("%d %d", &min, &max);
	}
	puts("����~");

	return 0;
}