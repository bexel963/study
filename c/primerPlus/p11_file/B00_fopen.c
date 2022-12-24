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
		printf("%s ������ �� �� �����ϴ�.\n", title);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("%s ���Ͽ��� %ld���� ���ڰ� ����ֽ��ϴ�.\n", title, count);

	return 0;
}