#include <stdio.h>
#define DEF "���� #define���� ���ǵ� ���ڿ��̴�."

int main(void)
{
	char str1[80] = "An array was initialized to me.";
	const char* str2 = "A pointer was initialized to me.";

	puts("���� puts()�� ���޵Ǵ� ���������̴�.");
	puts(DEF);
	puts(str1);
	puts(str2);
	puts(&str1[5]);
	puts(str2 + 4);

	// puts()�� �� ���ڸ� ������ �� �����.

	return 0;
}