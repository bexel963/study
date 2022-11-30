#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define STOP '|'

int main(void)
{
	char c;
	char prev;				// 바로 전에 읽은 문자
	long n_chars = 0L;
	int n_lines = 0;
	int n_words = 0;	
	int p_lines = 0;		// 불완전한 라인 수
	bool inword = false;	// c가 여전히 한 단어 안에 속해 있으면 true

	printf("분석할 영문 텍스트를 입력하시오(끝내려면 |): \n");
	prev = '\n';

	while ((c = getchar()) != STOP)
	{
		n_chars++;
		if (c == '\n')
			n_lines++;
		if (!isspace(c) && !inword)
		{
			inword = true;	// 새 단어를 시작한다.
			n_words++;
		}
		if (isspace(c) && inword)
		{
			inword = false;	// 단어의 끝에 도달했다.
			prev = c;		// 문자의 값을 보관한다.
		}
		
		if (prev != '\n')
			p_lines = 1;
		
	}
	printf("문자 수 = %ld, 단어수 = %ld, 라인 수 = %d, 불안전 라인수 = %d\n",
		n_chars, n_words, n_lines, p_lines);

	return 0;
}