#include <stdio.h>

int main(void)
{
	const int secret_code = 13;
	int code_entered;

	do {
		printf("��� �ڵ� �Է�: ");
		scanf("%d", &code_entered);
	} while (code_entered != secret_code);

	printf("��� �ڵ� ��ġ!!!\n");

	return 0;
}