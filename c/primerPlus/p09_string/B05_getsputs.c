/*
	- 기억공간 만들기

		: 컴퓨터는 문자열을 읽을 때 문자열의 길이를 카운트하여 필요한 만큼 기억 공간을 할당해 주지 않는다.
				char *name;
				scanf("%s", name);
		  위와 같이 시도하면 컴파일러는 이것을 통과 시킨다.
		  그러나 name을 읽었을 때 그 이름은 프로그램에 있는 데이터나 코드 위에 저장될 수 있다. 이것은 프로그램을 먹통으로 만들 수 있다.
		  그 이유는, scanf()가 전달인자로 제공된 주소에 그 정보를 복사하기 때문이다.
		  위 예의 경우, 그 전달인자는 초기화되지 않은 포인터이다. 그래서 name이 제멋대로 어딘가를 가리킬 것이다.

		: 위의 문제를 예방하기 가장 쉬운 방법은, 선언에 배열 크기를 명시적으로 지정하거나 메모리를 할당하는 C 라이브러리 함수를 사용하는 것이다.
				char name[81];

	- 문자열을 저장하기 위한 기억 공간을 할당했다면, 이제 그 문자열을 읽을 수 있다.
	  문자열을 읽을 수 있는 세 개의 함수 scanf(), gets(), fgets()를 C라이브러리가 제공한다.

		: scanf()와 %s 지정자는 한 단어만 읽는다.

		: gets()는 개행문자(\n)에 도달할 때까지 한 줄을 전부 읽고, 개행문자를 제거하고 C 문자열을 만들기 위해
		  널 문자(\0)를 추가하여 남은 문자를 저장한다.

		: gets()의 문제점은 gets()가 입력행이 실제로 배열에 딱 맞는지 볼 수 있도록 점검하지 않는다는 것이다.
		  gets()는 배열이 어디서 시작하는지만 알 뿐 원소가 몇 개 있는지는 모른다.
		  입력 문자열이 너무 길면, 버퍼 오버플로우가 나타나는데, 이것이(넘치는 문자들)사용되지 않는 메모리로 들어가며
		  프로그램에 다른 데이터를 겹쳐쓰는 등의 즉각적인 문제를 일으키거나 하지는 않고, 세그멘테이션 오류를 띄운다.
*/
#include <stdio.h>
#define STLEN 10

int main(void)
{
	char words[STLEN];

	puts("문자열을 입력해 주세요.");
	gets(words);
	
	printf("입력한 문자열이 두 번 반복될 것입니다.\n");
	printf("%s\n", words);
	puts(words);
	puts("종료!!");

	return 0;
}