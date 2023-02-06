#include <stdio.h>

int main(void)
{
	char* p = "Klingon";
	p[0] = 'F';	// 이 컴파일러로는 적용 안 됨

	puts(p);

	puts("Klingon");
	printf(": Beware the %ss!\n", "Klingon");

	return 0;
}