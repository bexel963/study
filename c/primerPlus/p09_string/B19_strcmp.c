#include <stdio.h>
#include <string.h>
#include "myString.h"
#define SIZE 80
#define LIM 10
#define STOP "quit"
char* s_get(char* st, int n);

// ���α׷��� �Է� �б⸦ ���� ���߾�� �ϴ����� �˻��ϱ� ���� strcmp()�� ����Ѵ�.
int main(void)
{
	char input[LIM][SIZE];
	int ct = 0;

	printf("%d���α��� �Է��Ͻʽÿ�.(�������� quit):\n", LIM);
	while (ct < LIM && (gets(input[ct]) != NULL) && (strcmp(input[ct], STOP) != 0))
	{
		ct++;
	}
	printf("%d���� ���ڿ��� �ԷµǾ����ϴ�.\n", ct);

	return 0;
}