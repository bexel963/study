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
		fprintf("stderr", "����: %s filename\n", argc);
		exit(EXIT_FAILURE);
	}
	if ((in = fopen(title, "r")) == NULL)
	{
		fprintf(stderr, "\"%s\" ������ �� �� ����.\n", title);
		exit(EXIT_FAILURE);
	}
	strncpy(name, reduceTitle, LEN - 5);
	name[LEN - 5] = '\0';	// �� ���ڴ� .red�� �ִ� ��ħǥ�� ���� ���� ��������.
	strcat(name, ".red");
	if ((out = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "��� ������ ���� �� ����.\n");
		exit(3);
	}

	while ((ch = getc(in) != EOF))
		if (count++ % 3 == 0)
			putc(ch, out);

	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "���ϵ��� �ݴ� �� ������ �߻��ߴ�.\n");

	return 0;
}
/*
	- �� ����(in, out)�� ���� ���������� ������ ������.
	  ���ÿ� ���� ���� �� �ִ� ���ϵ��� �������� ������ �ִ�. �� ������ ����ϴ� �ý��۰� �����Ϸ��� ���� �ٸ���.
	  �Ϲ������� �� ������ 10~20���̴�. 
	  ������ ���ÿ� ���� ���� �ʴ´ٸ�, ���� �ٸ� ���Ͽ� ���� ���� �����͸� ����� �� �ִ�.
*/