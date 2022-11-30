#include <stdio.h>

int main(void)
{
	int n;

	printf("3개의 정수 입력: ");
	scanf("%*d %*d %d", &n);
	printf("마지막으로 입력한 정수는 %d이다.\n", n);

	return 0;
}