#include <stdio.h>

int main(void)
{
	int code;
	char ch;

	printf("아스키 코드 입력: ");
	scanf("%d", &code);
	printf("아스키 코드 %d는 문자로 %c\n", code, code);
	getchar();
	printf("문자 하나 입력: ");
	scanf("%c", &ch);
	printf("문자 %c의 아스키코드 값은 %d\n\n", ch, ch);

	return 0;

	
}