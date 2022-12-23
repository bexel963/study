#include <stdio.h>
#include <string.h>
#define LISTSIZE 6

/*
	- strcmp()는 대응하는 두 문자가 일치하지 않는 문자 쌍을 찾을 때까지 문자열들을 비교한다.
	  이것은 둘 중 한 문자열의 끝에 도달할 때까지 검색이 이루어질 수 있다는 것을 의미한다.
	- strncmp()는 일치하지 않는 문자 쌍을 만날 때까지 또는 세 번째 전달인자로 지정한 문자들의 개수까지만 문자열들을 비교한다.
*/
int main(void)
{
	const char* list[LISTSIZE] = {
		"astronomy", "astrounding",
		"astrophysics", "ostracize",
		"asterism", "astrophobia"
	};
	int count = 0;
	int i;

	for (i = 0; i < LISTSIZE; i++)
	{
		if (strncmp(list[i], "astro", 5) == 0)
		{
			printf("찾았다: %s\n", list[i]);
			count++;
		}
	}
	printf("astro로 시작하는 단어 %d개를 찾았다.\n", count);

	return 0;
}