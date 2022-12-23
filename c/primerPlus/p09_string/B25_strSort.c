#include <stdio.h>
#include <string.h>
#include "myString.h"

#define LIM 20
#define SIZE 81
#define HALT ""

void stsrt(char* [], int);

/*
	- ���ڿ��� ��ü�� ���ġ�ϴ� ��ſ� �� ���ڿ����� ����Ű�� �����͵��� ���ġ�Ѵ�.
	  ���� ���ν�����, input�� �ǵ帮�� �ʰ�, ptstr�� ���ġ�Ѵ�.
	  strcpy()�� ����Ͽ� input�� �ִ� �� ���ڿ��� ������ �¹ٲٴ� �ͺ��� �� ����� �ξ� ����.
	  �� ����� input�迭�� ���� ������ ������ �� �ִٴ� ������ ������ �ִ�.
*/
int main(void)
{
	char input[LIM][SIZE];	// �Է��� ������ �迭
	char* ptstr[LIM];		// ������ �������� �迭
	int ct = 0;				// �Է� ī��Ʈ
	int k = 0;				// ��� ī��Ʈ

	printf("�ִ� %d���α��� �Է��ϸ� �װ͵��� �����ϰڽ��ϴ�.\n", LIM);
	printf("�Է��� ���߷��� ���� ���ۿ��� Enter Ű�� ����ÿ�.\n");
	while (ct < LIM && gets(input[ct]) != NULL && input[ct][0] != '\0')
	{
		ptstr[ct] = input[ct];
		ct++;
	}
	stsrt(ptstr, ct);
	puts("\n���ڿ����� ���ĵ� ���:\n");
	for (k = 0; k < ct; k++)
		puts(ptstr[k]);

	return 0;
}

void stsrt(char* strings[], int num)
{
	char* temp;
	int top, seek;

	for (top = 0; top < num - 1; top++)
	{
		for (seek = top + 1; seek < num; seek++)
		{
			if (strcmp(strings[top], strings[seek]) > 0)
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
		}
	}
}