#include <stdio.h>

int main(void)
{

	char alphabet[26];
	char ch = 'a';

	int length = sizeof(alphabet);
	
	for (int i = 0; i < length; i++)
		alphabet[i] = ch++;

	for (int i = 0; i < length; i++)
		printf("%c ", alphabet[i]);

	putchar('\n\n');

	return 0;
}