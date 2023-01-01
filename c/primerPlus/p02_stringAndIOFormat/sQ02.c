#include <stdio.h>
#include <string.h>

int main(void)
{
	char name[30];
	int width;

	printf("이름 입력: ");
	scanf("%s", name);
	
	width = strlen(name) + 3;

	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("\"%*s\"\n\n", width, name);

	return 0;
}