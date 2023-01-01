#include <stdio.h>
#define PRAISE "You are an extraordinary being."

int main(void)
{
	char name[40];

	printf("성함이 어떻게 되시나요?\n");
	scanf("%s", name);
	printf("반갑습니다. %s씨. %s\n", name, PRAISE);

	scanf("%s", name);
	printf("%s\n\n", name);

	return 0;
}