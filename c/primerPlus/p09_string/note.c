#include <stdio.h>

int main(void)
{
	char* p = "Klingon";
	p[0] = 'F';	// �� �����Ϸ��δ� ���� �� ��

	puts(p);

	puts("Klingon");
	printf(": Beware the %ss!\n", "Klingon");

	return 0;
}