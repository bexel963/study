#include <stdio.h>

int main(void)
{
	float f;

	printf("소수점 수 하나 입력: ");
	scanf("%f", &f);	
	printf("입력된 것은 %.1f 또는 %.1e 이다.\n", f, f);
	
	getchar();

	printf("소수점 수 하나 입력: ");
	scanf("%f", &f);
	printf("입력된 것은 %+.3f 또는 %.3E 이다.\n\n", f, f);

	return 0;
	
}