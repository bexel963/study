#include <stdio.h>

int units = 0;
void critic(void);

int main(void)
{
	extern int units;	// �������� �缱��

	printf("���� �� �� ������ �� �Ŀ������ �Ƽ���?\n");
	scanf("%d", &units);
	while (units != 56)
	{
		critic();
	}
	printf("�̸� ������ �˰� �־�����!\n");

	return 0;
}

void critic(void)
{
	/*�������� �缱���� �����Ǿ���.*/
	printf("Ʋ�Ƚ��ϴ�. �ٽ� ���纸����.\n");
	scanf("%d", &units);
}