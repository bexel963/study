#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 20

char* string_in(const char*, const char*);

int main(void)
{
	char* str = "abcdefghijklmnopqrstuvwxyz";
	char search[SIZE];
	char* find;
	int cnt;
	
	fputs("찾으려는 문자열 입력([Enter]): ", stdout);
	while (fgets(search, SIZE, stdin) != NULL && search[0] != '\n')
	{
		cnt = 0;
		while (search[cnt] != '\n' && search[cnt] != '\0')
			cnt++;
		if (search[cnt] == '\n')
			search[cnt] = '\0';
		else
			while (getchar() != '\n')
				continue;

		find = string_in(str, search);
		if (find)
		{
			fputs("\n찾으려는 문자열 부터 출력: ", stdout);
			puts(find);
		}
		else
			puts("\n찾으려는 문자열이 없습니다.");
						
		fputs("찾으려는 문자열 입력([Enter]): ", stdout);
	}
}

char* string_in(const char* str, const char* search)
{
	const char* strPtr = str;
	const char* searchPtr = search;
	char* tmp;
	bool findFirstChar = false;

	while (*strPtr != '\0')
	{
		if (*strPtr == *searchPtr)
		{
			size_t cnt = 0;
			findFirstChar = true;
			tmp = strPtr;
			while (cnt < strlen(search))
			{
				if (*tmp != *searchPtr)
				{
					findFirstChar = false;
					break;
				}					
				tmp++;
				searchPtr++;
				cnt++;
			}

			if (findFirstChar)
			{
				return strPtr;
			}				
		}
		
		strPtr++;
	}
	return NULL;

	
}