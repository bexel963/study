#include <stdio.h>

int main(void)
{
	const int secret_code = 13;
	int code_entered;
	
	printf("��� �ڵ� �Է�: ");
	scanf("%d", &code_entered);
	while (code_entered != secret_code)
	{
		printf("��� �ڵ� �Է�: ");
		scanf("%d", &code_entered);
	}
	printf("��� �ڵ� ��ġ!!!\n");

	return 0;
}