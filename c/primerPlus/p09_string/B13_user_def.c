#include <stdio.h>
void put1(const char*);
int put2(const char*);

int main(void)
{
	put1("������� �� �� ���� ��ŭ");
	put2(" ���� ǳ���ϸ� �� �����ø�,\n");
	printf("���� %d���� ���ڵ��� ī��Ʈ�ߴ�.\n", put2("���� ������ ���� ���ڵ�� ������ ���� ���̴�."));

	return 0;
}
void put1(const char* string)
{
	while (*string)				// *string != '\0' �� ����.
		putchar(*string++);
}
int put2(const char* string)
{
	int count = 0;
	while (*string)
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');

	return count;
}