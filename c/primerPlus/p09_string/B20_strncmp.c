#include <stdio.h>
#include <string.h>
#define LISTSIZE 6

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