#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
	FILE* fp;
	char words[MAX];

	if ((fp = fopen("wordy.txt", "a+")) == NULL)
	{
		fprintf(stdout, "Cant't open \"wordy\" ������ �� �� �����ϴ�.\n");
		exit(EXIT_FAILURE);
	}
	puts("���Ͽ� �߰��� �ܾ���� �Է��Ͻÿ�. �Է��� ��������");
	puts("������ ���� ��ġ���� # Ű�� �����ÿ�.");
	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
		fprintf(fp, "%s\n", words);

	puts("���� ����:");
	rewind(fp);		// ���� �����͸� ������ �������� �ű��.
	while (fscanf(fp, "%s", words) == 1)
		puts(words);
	puts("����!");
	if (fclose(fp) != 0)
		fprintf(stderr, "������ �ݴ� �� ������ �߻��߽��ϴ�.\n");

	return 0;
}