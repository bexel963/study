#include <stdio.h>

int main(void)
{
	const char* mesg = "���Ҹ� �Ǵ����� ����!";
	const char* copy;

	copy = mesg;
	printf("%s\n", copy);
	printf("mesg = %s, &mesg = %p, �� = %p\n", mesg, &mesg, mesg);
	printf("copy = %s, &copy = %p, �� = %p\n", copy, &copy, copy);

	return 0;
}