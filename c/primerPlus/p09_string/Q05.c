#include <stdio.h>
#include <string.h>

char* getCharacter(char*, char);

int main(void)
{
	char* str = "abcdefghijklmnopqrstuvwxyz";
	char search;
	char* find;

	printf("찾을 문자 하나 입력(끝내려면 [Enter]입력): ");
	while ((search = getchar()) != '\n')
	{
		find = getCharacter(str, search);

		if (!find)
			puts("찾으려는 문자가 없습니다.");
		else
			printf("찾으려는 문자는 %c가 있습니다.\n", *find);

		while (getchar() != '\n')
			continue;
		printf("찾을 문자 하나 입력(끝내려면 [Enter]입력): ");
	}
}

char* getCharacter(const char* str, char search)
{
	char* ptr = str;

	while (*ptr != '\0')
	{
		if (*ptr == search)
			return ptr;
		ptr++;
	}
	
	return NULL;
	
}