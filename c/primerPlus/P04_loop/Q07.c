#include <stdio.h>
#include <string.h>

int main(void)
{
	char word[20];
	int length;

	printf("�ܾ� �ϳ� �Է�: ");
	scanf("%s", word);
	
	length = strlen(word);

	for (length; length >= 0; length--)
	{
		putchar(word[length]);
	}
	putchar('\n');

	return 0;
}