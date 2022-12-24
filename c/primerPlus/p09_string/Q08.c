#include <stdio.h>
#define LEN 100

char* string_in(char*, char*);

int main(void)
{
	char source[LEN] = "abcdaefghijaehyungscxvoisd";
	char item[LEN];
	int i;
	char* result;

	fputs("찾을 문자열을 입력(종료하려면 [enter]입력): ", stdout);
	while (fgets(item, 10, stdin) != NULL && item[0] != '\n')
	{
		i = 0;
		while (item[i] != '\n' && item[i] != '\0')
		{
			i++;
		}			
		if (item[i] == '\n') {
			item[i] = '\0';
		}			
		else
		{
			while (getchar() != '\n')
				continue;
		}
		
		fputs("찾으려고 하는 문자열: ", stdout);
		puts(item);

		result = string_in(source, item);
		
		if (result)
		{
			fputs("찾음!! 찾은 문자열 부터 출력: ", stdout);
			puts(result);
		}
		else
			puts("못 찾음 ㅠㅠ");
		fputs("찾을 문자열을 입력(종료하려면 [enter]입력): ", stdout);
	}
	
	puts("\n종료\n");
}

char* string_in(char* source, char* item)
{
	// item의 첫 글자가 source에 있으면
		// item의 나머지 모든 글자도 source에 연달아 있는지 탐색
			// 있으면 item의 첫 글자의 주소 리턴
			// 없으면 다시 item의 첫글자와 일치하는 문자가 source에 있는지 탐색 -> 반복...
	char* ps = source;
	char* tmp;
	char* pi = item;
	char* result;
	int find = 0;

	while (*ps != '\0')
	{
		if (*ps == *pi)
		{
			tmp = ps;
			find = 1;
			while (*pi != '\0')
			{
				if (*(ps++) != *(pi++))
					find = 0;
			}
			if (find)
				return tmp;
			else
			{
				pi = item;
				ps = tmp;
			}			
		}
		ps++;
	}
	
	if (!find)
	{
		return NULL;
	}
}