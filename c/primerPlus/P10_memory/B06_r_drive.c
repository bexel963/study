#include <stdio.h>

extern void srand(unsigned int);
extern int rand(void);

int main(void)
{
	int count;
	unsigned seed;

	printf("���ڰ����� ����� ���� �Է��Ͻÿ�.\n");
	while (scanf("%u", &seed) == 1)
	{
		srand(seed);
		for (count = 0; count < 5; count++)
			printf("%hd\n", rand());
		printf("���� ���ڰ��� �Է��Ͻÿ�(�������� q):\n");
	}
	printf("����!\n");

	return 0;
}