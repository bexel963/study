/*
	- gets()에 대한 대안 -> fgets()
		
		: fgets()는 읽을 문자들의 최대 개수를 지정함으로써 두 번째 전달인자를 취할 때 생길 수 있는 오버플로우 문제를 해결한다.
		
		: fgets()는 파일 입출력용으로 설계된 것이기 때문에, 키보드 입력에서는 gets()보다 약간 불편하다.

	- fgets() vs gets()

		: fgets()는 읽을 문자들의 최대 개수를 지정하기 위해 두 번째 전달 인자를 사용한다.
		  그 전달인자가 값 n이라면, fgets()는 n-1개까지 문자들을 읽거나 개행 문자가 나올 때까지 읽는다. 둘 중 먼저 일어나는 것을 수행한다.

		: fgets()는 개행 문자를 읽어 그 문자열에 저장한다. gets()는 읽고 그냥 버린다.

		: fgets()는 어느 파일을 읽을 것인지 지정하기 위해 세 번째 전달인자를 사용한다. 키보드로부터 읽으려면 stdin(standard input)을 전달인자로 사용한다.

		: fgets()가 문자열의 부분으로서 개행을 포함하기 때문에 이 함수는 종종 puts()와 같이 일하는 fputs()와 짝을 이뤄 사용하는데,
		  fputs()는 자동으로 개행을 추가하지는 않는다. (puts()는 자동으로 개행을 추가한다.)
		  fputs()는 어느 파일에 쓸지 가리키기위해 두 번째 전달인자를 사용한다.
		  컴퓨터 모니터인 경우 stdout을 전달인자로 사용하면 된다.
*/

#include <stdio.h>
#define STLEN 14

int main(void)
{
	char words[STLEN];

	puts("문자열을 입력하세요.");
	fgets(words, STLEN, stdin);
	printf("입력한 문자열 두 번 (puts(), 그리고 나서 fputs()): \n");
	
	puts(words);
	fputs(words, stdout);
	
	puts("다른 문자열을 입력하세요.");
	fgets(words, STLEN, stdin);
	printf("입력한 문자열 두 번 (puts(), 그리고 나서 fputs()): \n");
	
	puts(words);
	fputs(words, stdout);
	puts("Done.");

	return 0;
}
/*
	- 입력 -> strawberry shortcake

		: strawberry shortcake 는 크기 한계를 초과하므로 fgets()는 첫 문자 13개를 읽어 배열에 strawberry sh\0 을 저장한다.
		
		: puts는 개행을 출력에 추가하고, fpust()는 추가하지 않는다.

*/