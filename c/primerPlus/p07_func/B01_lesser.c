#include <stdio.h>
int imin(int, int);

int main(void)
{
	int evil1, evil2;

	printf("�� ������ �Է��Ͻÿ�(�������� q): \n");
	while (scanf("%d %d", &evil1, &evil2) == 2)
	{
		printf("(%d, %d)���� ���� ���� %d\n", evil1, evil2, imin(evil1, evil2));
		printf("�� ������ �Է��Ͻÿ�(�������� q) : \n");
	}
	printf("����\n");

	return 0;
}



int imin(int x, int y)
{
	int min;

	if (x < y)
		min = x;
	else
		min = y;

	return min;
}