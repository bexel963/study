#include <stdio.h>
#include <limits.h>	// ������ �Ѱ�
#include <float.h>	// �ε��Ҽ����� �Ѱ�

int main(void)
{
	printf("char���� ũ��: %dbyte\n", sizeof(char));
	printf("char���� ��Ʈ��: %d\n", CHAR_BIT);
	printf("char���� �ִ밪: %d\n", CHAR_MAX);
	printf("signed char���� �ʴ밪: %d\n", CHAR_MAX);
	printf("signed char���� �ּҰ�: %d\n", CHAR_MIN);
	printf("unsigned char���� �ִ밪: %d\n\n", UCHAR_MAX);
	printf("short���� ũ��: %dbyte\n", sizeof(short));
	printf("short���� �ִ밪: %d\n", SHRT_MAX);
	printf("short���� �ּҰ�: %d\n", SHRT_MIN);
	printf("unsigned short���� �ִ밪: %d\n\n", USHRT_MAX);
	printf("int���� ũ��: %dByte\n", sizeof(int));
	printf("int���� �ִ밪: %d\n", INT_MAX);
	printf("int���� �ּҰ�: %d\n", INT_MIN);
	printf("unsigned int���� �ִ밪: %d\n\n", UINT_MAX);
	printf("long���� ũ��: %dbyte\n", sizeof(long));
	printf("long���� �ִ밪: %ld\n", LONG_MAX);
	printf("long���� �ּҰ�: %ld\n", LONG_MIN);
	printf("unsigned long���� �ִ밪: %ld\n\n", ULONG_MAX);
	printf("long long���� ũ��: %dbyte\n", sizeof(long long));
	printf("long long���� �ִ밪: %lld\n", LLONG_MAX);
	printf("long long���� �ּҰ�: %lld\n", LLONG_MIN);
	printf("unsigned long long���� �ִ밪: %lld\n\n", ULLONG_MAX);

	printf("--------------------------------\n");

	printf("float���� ������ ��Ʈ��: %d\n", FLT_MANT_DIG);
	printf("float���� �Ҽ��� �ּ� ��ȿ �ڸ���: %d\n", FLT_DIG);
	printf("float���� �ִ� ��ȿ���ڸ� ���� �ּ� 10�� ��������: %d\n", FLT_MIN_10_EXP);
	printf("float���� �ִ� 10�� ���� ����: %d\n", FLT_MAX_10_EXP);
	printf("float���� �ִ� ���е��� ���� ���� �ּҰ�: %e\n", FLT_MIN);
	printf("float���� ���� �ִ밪: %e\n", FLT_MAX);
	printf("1.00�� �ּ��� 1.00���� ū float�� ���� ��: %e\n", FLT_EPSILON);

	return 0;
}