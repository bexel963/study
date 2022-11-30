#include <stdio.h>
#include <limits.h>	// 정수의 한계
#include <float.h>	// 부동소수점의 한계

int main(void)
{
	printf("char형의 크기: %dbyte\n", sizeof(char));
	printf("char형의 비트수: %d\n", CHAR_BIT);
	printf("char형의 최대값: %d\n", CHAR_MAX);
	printf("signed char형의 초대값: %d\n", CHAR_MAX);
	printf("signed char형의 최소값: %d\n", CHAR_MIN);
	printf("unsigned char형의 최대값: %d\n\n", UCHAR_MAX);
	printf("short형의 크기: %dbyte\n", sizeof(short));
	printf("short형의 최대값: %d\n", SHRT_MAX);
	printf("short형의 최소값: %d\n", SHRT_MIN);
	printf("unsigned short형의 최대값: %d\n\n", USHRT_MAX);
	printf("int형의 크기: %dByte\n", sizeof(int));
	printf("int형의 최대값: %d\n", INT_MAX);
	printf("int형의 최소값: %d\n", INT_MIN);
	printf("unsigned int형의 최대값: %d\n\n", UINT_MAX);
	printf("long형의 크기: %dbyte\n", sizeof(long));
	printf("long형의 최대값: %ld\n", LONG_MAX);
	printf("long형의 최소값: %ld\n", LONG_MIN);
	printf("unsigned long형의 최대값: %ld\n\n", ULONG_MAX);
	printf("long long형의 크기: %dbyte\n", sizeof(long long));
	printf("long long형의 최대값: %lld\n", LLONG_MAX);
	printf("long long형의 최소값: %lld\n", LLONG_MIN);
	printf("unsigned long long형의 최대값: %lld\n\n", ULLONG_MAX);

	printf("--------------------------------\n");

	printf("float형의 가수부 비트수: %d\n", FLT_MANT_DIG);
	printf("float형의 소수부 최소 유효 자릿수: %d\n", FLT_DIG);
	printf("float형의 최대 유효숫자를 가진 최소 10진 음의지수: %d\n", FLT_MIN_10_EXP);
	printf("float형의 최대 10진 양의 지수: %d\n", FLT_MAX_10_EXP);
	printf("float형의 최대 정밀도를 가진 양의 최소값: %e\n", FLT_MIN);
	printf("float형의 양의 최대값: %e\n", FLT_MAX);
	printf("1.00과 최소한 1.00보다 큰 float형 값의 차: %e\n", FLT_EPSILON);

	return 0;
}