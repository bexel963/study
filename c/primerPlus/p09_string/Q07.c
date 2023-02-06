#include <stdio.h>
#define SIZE 20

char* mystrncpy(char*, char*, int);

int main(void)
{
	char target[SIZE];
	char source[SIZE];
	int cnt;

	fputs("소스 문자열 입력(끝내려면 [Enter]입력): ", stdout);
	while (fgets(source, 10, stdin) != NULL && source[0] != '\n')
	{
		cnt = 0;
		while (source[cnt] != '\n' && source[cnt] != '\0')
			cnt++;
		if (source[cnt] == '\n')
			source[cnt] == '\0';
		else
			while (getchar() != '\n')
				continue;

		fputs("\nsource배열에 저장된 문자열: ", stdout);
		puts(source);
			
		fputs("target배열에 복사된 문자열: ", stdout);
		if (mystrncpy(target, source, 5) != NULL)
		{			
			puts(target);
		}
		
		fputs("\n소스 문자열 입력(끝내려면 [Enter]입력): ", stdout);
	}
	
	return 0;
}

char* mystrncpy(char* target, char* source, int length)
{
	for (int i = 0; i < length; i++)
		target[i] = source[i];
	target[length] = '\0';
	
	return target;
}