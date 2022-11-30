#include <stdio.h>

int main(void)
{
	const int secret_code = 13;
	int code_entered;

	do {
		printf("비밀 코드 입력: ");
		scanf("%d", &code_entered);
	} while (code_entered != secret_code);

	printf("비밀 코드 일치!!!\n");

	return 0;
}