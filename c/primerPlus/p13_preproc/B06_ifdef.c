#include <stdio.h>
#define JUST_CHECKING
#define LIMIT 4

int main(void)
{
	int i;
	int total = 0;
	
	for (i = 0; i <= LIMIT; i++)
	{
		total += 2 * i * i + 1;
#ifdef JUST_CHECKING	// JUST_CHECKING ���� �����ϸ� '�Ѱ�' �� ��µ�.
		printf("i = %d, ���� = %d\n", i, total);
#endif
	}
	printf("�Ѱ� = %d\n", total);

	return 0;
}