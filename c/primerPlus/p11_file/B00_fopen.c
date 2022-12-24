#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ch;
	FILE* fp;
	unsigned long count = 0;
	char* title = "test.txt";

	if ((fp = fopen(title, "r")) == NULL)
	{
		printf("%s 파일을 열 수 없습니다.\n", title);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("%s 파일에는 %ld개의 문자가 들어있습니다.\n", title, count);

	return 0;
}