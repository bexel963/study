#include <stdio.h>
#include <string.h>
#define WORDS "beast"
#define SIZE 40

int main(void)
{
	const char* orig = WORDS;
	char copy[SIZE] = "Be the best that you can be.";
	char* ps;

	puts(orig);
	puts(copy);
	ps = strcpy(copy + 7, orig);	// strcpy()는 첫 번째 전달인자의 값(문자의 주소)(copy+7)를 리턴한다.
	puts(copy);						// strcpy()는 소스 문자열로부터 널 문자도 복사한다.
	puts(ps);

	puts("\n--------------");
	for (int i = 0; i < SIZE; i++)
		if (copy[i] == '\0')
			putchar(' ');
		else
			putchar(copy[i]);

	return 0;
}