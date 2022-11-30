#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define STOP '|'

int main(void)
{
	char c;
	char prev;				// �ٷ� ���� ���� ����
	long n_chars = 0L;
	int n_lines = 0;
	int n_words = 0;	
	int p_lines = 0;		// �ҿ����� ���� ��
	bool inword = false;	// c�� ������ �� �ܾ� �ȿ� ���� ������ true

	printf("�м��� ���� �ؽ�Ʈ�� �Է��Ͻÿ�(�������� |): \n");
	prev = '\n';

	while ((c = getchar()) != STOP)
	{
		n_chars++;
		if (c == '\n')
			n_lines++;
		if (!isspace(c) && !inword)
		{
			inword = true;	// �� �ܾ �����Ѵ�.
			n_words++;
		}
		if (isspace(c) && inword)
		{
			inword = false;	// �ܾ��� ���� �����ߴ�.
			prev = c;		// ������ ���� �����Ѵ�.
		}
		
		if (prev != '\n')
			p_lines = 1;
		
	}
	printf("���� �� = %ld, �ܾ�� = %ld, ���� �� = %d, �Ҿ��� ���μ� = %d\n",
		n_chars, n_words, n_lines, p_lines);

	return 0;
}