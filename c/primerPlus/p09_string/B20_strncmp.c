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
			printf("ã�Ҵ�: %s\n", list[i]);
			count++;
		}
	}
	printf("astro�� �����ϴ� �ܾ� %d���� ã�Ҵ�.\n", count);

	return 0;
}