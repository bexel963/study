#include <stdio.h>
#define LEN 100

char* search(char*, char);

int main(void)
{

	char sentence[LEN] = "abcdefghiz klm";
	char input;
	char* result;

	fputs("문자 하나 입력(끝내려면 [enter]): ", stdout);
	while ((input = getchar()) != '\n')
	{
		result = search(sentence, input);
		if (result != NULL)		
			printf("찾기 성공!! 찾은 문자부터 출력 합니다: %s", result);		
		else
			puts("입력한 문자가 없습니다.");

		while (getchar() != '\n')
			continue;

		fputs("\n문자 하나 입력(끝내려면 [enter]): ", stdout);		
	}

}

char* search(char* str, char ch)
{
	int idx = 0;

	while (str[idx] != ch && str[idx] != '\0')
	{
		idx++;
	}

	if (str[idx] == ch)
		return &str[idx];
	else
		return NULL;
}