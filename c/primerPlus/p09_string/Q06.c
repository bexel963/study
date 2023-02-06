#include <stdio.h>

int is_within(char, char*);

int main(void)
{
	char* str = "abcdefghijklmnopqrstuvwxyz";
	char search;
	int isFind;
	
	puts("문자 하나를 입력하면 입력한 문자가 해당 문자열에 있는지 알려준다.");
	printf("문자 하나 입력(끝내려면 [Enter]입력): ");
	while ((search = getchar()) != '\n')
	{
		isFind = is_within(search, str);
		
		if (isFind)
			puts("입력한 문자가 문자열에 들어있음.");
		else
			puts("입력한 문자가 문자열에 없음.");
		printf("문자 하나 입력(끝내려면 [Enter]입력): ");

		while (getchar() != '\n')
			continue;
	}

	return 0;
}

int is_within(char search, char* str)
{
	int idx = 0;

	while (str[idx] != '\0')
	{
		if (str[idx] == search)
			return 1;
		idx++;
	}

	return 0;
}