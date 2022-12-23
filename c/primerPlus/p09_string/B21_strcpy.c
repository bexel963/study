#include <stdio.h>
#include <string.h>
#include "myString.h"

#define SIZE 40
#define LIM 5

char* s_gets(char*, int);

int main(void)
{
	char qwords[LIM][SIZE];
	char temp[SIZE];
	int i = 0;

	printf("q�� �����ϴ� �ܾ %d�� �Է��Ͻÿ�: \n", LIM);
	while (i < LIM && s_gets(temp, SIZE))
	{
		if (temp[0] != 'q')
			printf("%s: q�� �����ϴ� �ܾ �ƴմϴ�.\n", temp);
		else
		{
			/*
				- strcpy()�� �� ���� ���ڿ� �����͸� �������ڷ� ����Ѵ�.
				  ����� ������, �迭 �̸�, ���ڿ� ����� �ҽ� ���ڿ��� ����Ű�� �� ��° �����Ͱ� �� �� �ִ�.
				  Ÿ�� ���ڿ��� ����Ű�� ù ��° �����ʹ�, �� ���ڿ��� ������ �� ���� ��ŭ ����� ��� ������ Ȯ���ϰ� �ִ�, �迭�� ����
				  ������ ��ü�� �����Ѿ� �Ѵ�.

				- �迭�� �����ϸ� �����͸� ���� ��� ������ �Ҵ�ǰ�, �����͸� �����ϸ� �ϳ��� �ּҸ� ���� ��� ������ �Ҵ�ȴ�.

				- Ÿ�� �迭�� �ҽ� �迭�� ������ �� ���� ��ŭ ����� ��� ������ ������ �ִ��� Ȯ���ϴ� ���� ���α׷����� ���̴�.

						char* str;
						strcpy(str, "The C of Tranquility");	// ���� �߻�

				  �� ��Ȳ���� �� �Լ��� ���ڿ� "The C of Tranquility"�� str�� �����ϴ� �ּҿ� �����Ѵ�.
				  �׷��� str�� �ʱ�ȭ���� �ʾұ� ������, ���� ������� �� ���� ����.
			*/
			strcpy(qwords[i], temp);
			i++;
		}
	}
	puts("�޾Ƶ��� �ܾ���� ������ �����ϴ�.");
	for (i = 0; i < LIM; i++)
		puts(qwords[i]);


	return 0;
}
