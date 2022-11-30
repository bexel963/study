#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	int32_t me32;	// me32는 32비트 부호있는 정수형 변수다.

	me32 = 45933945;
	printf("먼저, int32_t를 int형이라고 가정한다: ");
	printf("me32 = %d\n", me32);
	printf("이제, 어떠한 가정도 하지 말자.\n");
	printf("그 대신에, inttypes.h에 있는 \"macro\"를 사용한다: ");
	printf("me32 = %" PRId32 "\n", me32);	// PRId32는 inttypes.h에 정의되어 있는 "d"로 대체된다.

	return 0;
}