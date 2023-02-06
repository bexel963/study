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
		fprintf(stderr, "출력을 위한 %s 파일을 열 수 없습니다.\n", file);
		exit(EXIT_FAILURE);
	}
	
	fwrite(numbers, sizeof(double), ARSIZE, iofile);
	fclose(iofile);
	if ((iofile = fopen(file, "rb")) == NULL)
	{
		fprintf(stderr, "임의 접근을 위한 %s 파일을 열 수 없습니다.\n", file);
		exit(EXIT_FAILURE);
	}

	printf("0-%d 범위에서 하나의 인덱스를 입력하시오.\n", ARSIZE - 1);
	while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE)
	{
		pos = (long)i * sizeof(double);	// 오프셋 계산
		fseek(iofile, pos, SEEK_SET);	// 그 위치로 간다.
		fread(&value, sizeof(double), 1, iofile);
		printf("그 위치에 들어 있는 값은 %f입니다.\n", value);
		printf("다음 인덱스를 입력하시오(끝내려면 범위를 벗어난 인덱스):\n");
	}

	fclose(iofile);
	puts("안녕!");

	return 0;
}