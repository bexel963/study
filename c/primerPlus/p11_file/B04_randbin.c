#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000

int main(void)
{
	double numbers[ARSIZE];
	double value;
	const char* file = "numbers.dat";
	int i;
	long pos;
	FILE* iofile;
	
	for (i = 0; i < ARSIZE; i++)
		numbers[i] = 100 * i + 1.0 / (i + 1);

	if ((iofile = fopen(file, "wb")) == NULL)
	{
		fprintf(stderr, "����� ���� %s ������ �� �� �����ϴ�.\n", file);
		exit(EXIT_FAILURE);
	}
	
	fwrite(numbers, sizeof(double), ARSIZE, iofile);
	fclose(iofile);
	if ((iofile = fopen(file, "rb")) == NULL)
	{
		fprintf(stderr, "���� ������ ���� %s ������ �� �� �����ϴ�.\n", file);
		exit(EXIT_FAILURE);
	}

	printf("0-%d �������� �ϳ��� �ε����� �Է��Ͻÿ�.\n", ARSIZE - 1);
	while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE)
	{
		pos = (long)i * sizeof(double);	// ������ ���
		fseek(iofile, pos, SEEK_SET);	// �� ��ġ�� ����.
		fread(&value, sizeof(double), 1, iofile);
		printf("�� ��ġ�� ��� �ִ� ���� %f�Դϴ�.\n", value);
		printf("���� �ε����� �Է��Ͻÿ�(�������� ������ ��� �ε���):\n");
	}

	fclose(iofile);
	puts("�ȳ�!");

	return 0;
}