#include <stdio.h>

/*
	- fputs()는 puts()의 파일 지향 버전이다.
	  출력할 타깃 파일을 지정하기 위해 두 번째 전달인자를 사용한다.

	- gets()는 입력에 개행을 읽고 버린다.
	- fgets()는 입력에 개행 문자를 추가한다.

	- puts()는 출력에 개행을 추가한다.
	- fputs()는 출력에 개행을 추가하지 않는다.
*/
int main(void)
{
	char line1[10];
	char line2[10];

	puts("gets(), puts()를 사용한 echo");
	gets(line1);
	puts(line1);

	puts("fgets(), fputs()를 사용한 echo");
	fgets(line2, 81, stdin);
	fputs(line2, stdout);

	return 0;
}