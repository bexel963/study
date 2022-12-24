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
	name[LEN - 5] = '\0';	// 널 문자는 .red에 있는 마침표에 의해 덮어 쓰여진다.
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
/*
	- 두 파일(in, out)은 서로 독립적으로 열리고 닫힌다.
	  동시에 열어 놓을 수 있는 파일들의 개수에는 제한이 있다. 그 제한은 사용하는 시스템과 컴파일러에 따라 다르다.
	  일반적으로 그 제한은 10~20개이다. 
	  파일을 동시에 열어 놓지 않는다면, 서로 다른 파일에 같은 파일 포인터를 사용할 수 있다.
*/