#include <stdio.h>
#include <stdlib.h>
void sign_off(void);
void too_bad(void);

int main(void)
{
	int n;
	
	atexit(sign_off);
	puts("������ �Է��Ͻÿ�:");
	if (scanf("%d", &n) != 1)
	{
		puts("������ �ƴմϴ�!");
		atexit(too_bad);
		exit(EXIT_FAILURE);
	}
	printf("%d: %s\n", n, (n % 2 == 0) ? "¦��" : "Ȧ��");

	return 0;
}

void sign_off(void)
{
	puts("���α׷��� �����մϴ�.");
	puts("SeeSaw ����Ʈ����!");
}
void too_bad(void)
{
	puts("SeeSaw ����Ʈ����� ���ɾ �ֵ��� ǥ�մϴ�.");
	puts("���α׷��� ���������� �������� ���� �� ����");
}