#include <stdio.h>

int main(void)
{
	int code;
	char ch;

	printf("�ƽ�Ű �ڵ� �Է�: ");
	scanf("%d", &code);
	printf("�ƽ�Ű �ڵ� %d�� ���ڷ� %c\n", code, code);
	getchar();
	printf("���� �ϳ� �Է�: ");
	scanf("%c", &ch);
	printf("���� %c�� �ƽ�Ű�ڵ� ���� %d\n\n", ch, ch);

	return 0;

	
}