#include <stdio.h>
#include <string.h>

int main(void)
{
	char firstName[10];
	char lastName[20];
	int firstLength;
	int lastLength;

	printf("�̸� �Է�: ");
	scanf("%s", lastName);
	printf("�� �Է�: ");
	scanf("%s", firstName);
	
	firstLength = strlen(firstName);
	lastLength = strlen(lastName);
	
	printf("%s %s\n", firstName, lastName);
	printf("%*d %*d\n\n", firstLength, firstLength, lastLength, lastLength);

	printf("%s %s\n", firstName, lastName);
	printf("%d %*d\n\n", firstLength, lastLength-1, lastLength);

	return 0;
}