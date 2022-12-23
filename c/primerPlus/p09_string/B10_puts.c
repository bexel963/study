#include <stdio.h>
#define DEF "나는 #define으로 정의된 문자열이다."

int main(void)
{
	char str1[80] = "An array was initialized to me.";
	const char* str2 = "A pointer was initialized to me.";

	puts("나는 puts()에 전달되는 전달인자이다.");
	puts(DEF);
	puts(str1);
	puts(str2);
	puts(&str1[5]);
	puts(str2 + 4);

	// puts()는 널 문자를 만났을 때 멈춘다.

	return 0;
}