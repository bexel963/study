/*
	- 시스템은 버퍼를 사용하는 I/O를 사용한다. 이것은 입력이 리턴키가 눌려질 때까지 임시 메모리(버퍼)에 저장된다는 의미이다.
	  이것은 입력에 개행문자를 추가하여 전체 행을 fgets()상으로 보낸다.
	  출력상에서 fputs()는 또다른 버퍼에 문자들을 보내고, 개행이 보내졌을 때 버퍼의 내용은 화면상으로 보내진다.
*/

#include <stdio.h>
#define STLEN 10
/*
	- 입력행을 읽고 저장된 개행들을 삭제하고, 맞지 않는 행의 부분을 버리는 프로그램.

	- fgets2.c는 입력행의 나머지를 처리한다.
	- fgets3.c는 입력행의 나머지 부분을 없앤다.
*/
int main(void)
{
	char words[STLEN];
	int i;

	puts("문자열을 입력하세요 (탈출하려면 빈 행): ");
	while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
	{
		i = 0;
		while (words[i] != '\n' && words[i] != '\0')
		{
			i++;
		}
		if (words[i] == '\n')
			words[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
		puts(words);
	}
	puts("종료!!!");

	return 0;
}