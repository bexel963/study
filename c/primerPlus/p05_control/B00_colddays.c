#include <stdio.h>

int main(void)
{
	const int FREEZING = 0;
	float temperature;
	int cold_days = 0;
	int all_days = 0;

	printf("���� ��µ��� ����� �Է��Ͻÿ�.\n");
	printf("���� ������ ����Ͻÿ�(�Է��� �������� q).\n");
	while (scanf("%f", &temperature) == 1)
	{
		all_days++;
		if (temperature < FREEZING)
		{
			cold_days++;
		}
	}
	if (all_days != 0)
	{
		printf("��ü %d�� �߿� ������ ������ %.1f%%�����ϴ�.\n",
			all_days, 100 * (float)cold_days / all_days);
	}
	else {
		printf("�Է��� �����Ͱ� �����ϴ�.\n");
	}
	
	return 0;
}