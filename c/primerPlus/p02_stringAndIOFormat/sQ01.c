/*
	이름을 요청 -> 성 요청 -> 성, 이름 순으로 출력
*/
#include <stdio.h>

int main(void)
{
	char lastName[20];
	char firstName[10];

	printf("이름 입력: ");
	scanf("%s", lastName);
	getchar();
	printf("성 입력: ");
	scanf("%s", firstName);

	printf("%s%s\n\n", firstName, lastName);

	return 0;
}