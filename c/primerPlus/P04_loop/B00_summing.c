#include <stdio.h>

int main(void)
{
	long num = 0;
	long sum = 0L;
	int status;

	char ch;

	printf("���� ���� ���� �ϳ� �Է�!");
	printf("(�������� q): ");
	
	status = scanf("%ld", &num);	// ���� ���⼭ ���ڸ� �Է��ϸ� scanf()�� �Է��� ���� �ʰ� �ش� ���ڸ� �Է� ť�� �ǵ�����.
	printf("\n\n%d\n", status);	// �б⿡ �����Ͽ� 0�� ��ȯ�ȴ�.
	status = scanf("%c", &ch);		// �ǵ����� ���ڸ� ���⼭ �аԵȴ�.
	while (status == 1)
	{
		sum += num;
		printf("���� ���� �Է�!(�������� q): ");
		status = scanf("%ld", &num);
	}
	printf("�Էµ� �������� ��: %ld\n", sum);

	return 0;
}