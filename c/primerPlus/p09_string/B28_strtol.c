#include <stdio.h>
#include <stdlib.h>
#define LIM 30

/*
	- ���ڿ��� ������ ���۵Ǵ� ���ڿ��̶�� atoi()�� �����Ѵ�. �׷� ��쿡, atoi()�� ���� �κ��� �ƴ� ���� ���� �� ����
	  �� ���� ���ڵ鸸 ��ȯ�Ѵ�.
		ex) atoi("42regular")�� ���� 42�� �����Ѵ�.

	- atoi("hello what?")�� ���� Ÿ�����ϸ� �׷��� ��� ANSIǥ���� ������ ���ǵ��� �ʴ´ٰ� ���Ѵ�.
	  STRTOL()�� �� �� �ŷ��� �� �ִ� ���� üũ ����� �����Ѵ�.
*/

/*
	long strtol(const char *nptr, char **endptr, int base);

		: strtol()�� ���ڿ��� long������ ��ȯ�Ѵ�.
		: strtol()�� ���ڿ����� ���� �ƴ� �κ��� ù ��° ���ڸ� �ν��ϰ� �����Ѵ�.
		: nptr�� ��ȯ�ϱ⸦ ���ϴ� ���ڿ��� ����Ű�� �������̴�.
		: endptr�� �������� �ּ��̴�. (�� �����ʹ� �Է��� ���� ������ ����, �� ���� �ƴ� �κ��� ù ��° ������ �ּ��̴�.)
		: base�� �� ���� ǥ���� ������ �����.
*/
char* s_gets(char*, int);

int main(void)
{
	char number[30];
	char* end;
	long value;
	
	puts("�ϳ��� ���� �Է��Ͻÿ�(�������� �� ���� �Է�):");
	while (s_gets(number, LIM) && number[0] != '\0')
	{
		value = strtol(number, &end, 10);	// 10����
		printf("��: %ld, %s �տ��� ������ (%d)\n", value, end, *end);

		value = strtol(number, &end, 16);	// 16����
		printf("��: %ld, %s �տ��� ������ (%d)\n", value, end, *end);
		puts("���� ���� �Է��Ͻÿ�:");
	}
	puts("�ȳ�!\n");

	/*
		- �Է� -> 10
			: �� ���ڸ� ������ �� �����ϹǷ� end�� �� ���ڸ� ����Ų��.
			: end ����� �� ���ڿ��� ǥ���Ѵ�.
			: %d ���� �����ڸ� ����� *end ����� �� ���ڿ� �ش��ϴ� ASCII �ڵ尪�� ǥ���Ѵ�.

		- �Է� -> 10atom
			: end�� 'a' ������ �ּҰ� �־�����. �׷��Ƿ� end ����� ���ڿ� "atom"�� ǥ���ϰ�,
			  *end ����� 'a' ���ڿ� �ش��ϴ� ASCII �ڵ尪�� ǥ���Ѵ�.
	*/
	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\n')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}