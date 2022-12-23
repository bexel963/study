#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20
int main(void)
{
	FILE* in, * out;
	int ch;
	char name[LEN];
	int count = 0;
	int argc = 2;

	char* title = "reduce.txt";
	char* reduceTitle = "eddy";

	if (argc < 2)
	{
		fprintf("stderr", "사용법: %s filename\n", argc);
		exit(EXIT_FAILURE);
	}
	if ((in = fopen(title, "r")) == NULL)
	{
		fprintf(stderr, "\"%s\" 파일을 열 수 없다.\n", title);
		exit(EXIT_FAILURE);
	}
	strncpy(name, reduceTitle, LEN - 5);
	name[LEN - 5] = '\0';
	strcat(name, ".red");
	if ((out = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "출력 파일을 만들 수 없다.\n");
		exit(3);
	}

	while ((ch = getc(in) != EOF))
		if (count++ % 3 == 0)
			putc(ch, out);

	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "파일들을 닫는 데 에러가 발생했다.\n");

	return 0;
}