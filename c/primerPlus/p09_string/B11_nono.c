#include <stdio.h>

int main(void)
{
	char side_a[] = "Side A";
	char dont[] = { 'W', '0', 'W', '!' };
	char side_b[] = "Side B";

	/*
		- dont는 종결 널 문자가 없기 때문에 문자열이 아니다.
		  그래서 puts()는 어디에서 멈추어야 하는지 알지 못한다.
		  그래서 어딘가에 있는 널 문자를 만날 때까지 dont부터 시작해서 그 뒤의 메모리 내용을 계속 출력한다.
	*/
	puts(dont);

	return 0;
}