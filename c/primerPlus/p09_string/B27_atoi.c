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
		printf("사용법: %s 양수값\n", argv[0]);
	}
	else
	{
		for (int i = 0; i < times; i++)
			puts("안녕, 얼굴이 좋아 보이는데!");
	}
	
	return 0;
}