#include <stdio.h>

int main(void)
{
	int spcCnt = 0;
	int newLineCnt = 0;
	int letterCnt = 0;
	char input;

	puts("���� �Է�: ");
	while ((input = getchar()) != '#')	// p06_io�� ���� ����
	{
		switch (input)
		{
		case ' ':
			spcCnt++;
			break;
		case '\n':
			newLineCnt++;
			break;
		default:
			letterCnt++;
			break;
		}
	}
	printf("��ĭ ��          : %d\n���๮�� ��      : %d\n��Ÿ ��� ���� ��: %d\n", spcCnt, newLineCnt, letterCnt);

	return 0;
}