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
	ps = strcpy(copy + 7, orig);	// strcpy()�� ù ��° ���������� ��(������ �ּ�)(copy+7)�� �����Ѵ�.
	puts(copy);						// strcpy()�� �ҽ� ���ڿ��κ��� �� ���ڵ� �����Ѵ�.
	puts(ps);

	puts("\n--------------");
	for (int i = 0; i < SIZE; i++)
		if (copy[i] == '\0')
			putchar(' ');
		else
			putchar(copy[i]);

	return 0;
}