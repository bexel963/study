#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int argc = 2;
	char* argv[2];
	int times;

	argv[0] = "hello";
	argv[1] = "3";
	
	if (argc < 2 || (times = atoi(argv[1])) < 1)
	{
		printf("����: %s �����\n", argv[0]);
	}
	else
	{
		for (int i = 0; i < times; i++)
			puts("�ȳ�, ���� ���� ���̴µ�!");
	}
	
	return 0;
}