#include <stdio.h>

int main(void)
{
	float speed;
	float size;

	printf("다운로드 속도와 파일 크기 입력: ");
	scanf("%f %f", &speed, &size);

	printf("초당 %.2f 메가비트, %.2f 메가바이트 파일을\n%.2f초에 다운로드한다.\n\n", speed, size, size/(speed/8));

	return 0;
}