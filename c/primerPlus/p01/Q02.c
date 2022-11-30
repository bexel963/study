#include <stdio.h>

int main(void)
{
	int code;
	
	printf("아스키 코드 입력: ");
	scanf("%d", &code);
	printf("아스키 코드 %d는 문자로 %c\n", code, code);
}