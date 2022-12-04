#include <stdio.h>
#define STLEN 10

int main(void)
{
	char words[STLEN];
	puts("문자열을 입력하세요 (탈출하려면 빈 행): ");
	while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
	{
		fputs(words, stdout);
	}
	puts("\n종료!!!");

	return 0;
}

/*
	- 입력 -> "By the way, the gets() funcion"

		: fgets()는 char로 포인터를 리턴한다. 문제가 없다면 그것을 첫 번째 전달 인자로서 보내졌던 것과 같은 주소로 리턴한다.
		  그러나 fgets()가 파일끝을 만나면 널 포인터라는 특별한 포인터를 리턴한다.
		  (널포인터는 특별한 경우를 가리키는데 사용될 수 있도록 유효한 데이터를 가리키지 않도록 보증된 포인터이다.)
		  (코드에서 널포인터는 숫자 0으로 나타내지거나, C에서는 보다 범용적으로 macro NULL로 표현된다.)

		: fgets()가 입력 STLEN을 한 번에 한문자(즉, 9)씩 읽는다. 따라서 "By the wa"를 읽는 것을 시작으로 By the wa\0 에 그것을 저장한다.
		  그 다음 fgets()는 원래 입력에서 중단된 부분 다음을 다시 읽는다. 즉, "y, the ge"을 읽고 그것을 y, the ge\0 으로 저장한다.
		  그리고 나서 fgets()는 다시 입력을 읽고 등등, "tion\n" 이 남을 때까지(파일 끝을 만날때까지) 이 과정을 반복한다.
		  fgets()는 tion\n\0 을 저장하고 fputs()는 그것을 출력한다.
		
*/