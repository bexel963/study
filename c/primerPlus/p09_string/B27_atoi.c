#include <stdio.h>
#include <stdlib.h>


/*
	- ���� ���ڿ� ���·� �Ǵ� ��ġ ���·� ������ �� �ִ�.
	  ȭ�鿡 ���� ǥ���� ����, ���ڷ� ǥ���ؾ� �ϹǷ� ���ڿ� ���¸� �䱸�Ѵ�.

	- atoi()
		: ���ڿ��� ������ ���۵Ǵ� ���ڿ��̸� atoi()�� �����Ѵ�.
		  �׷� ��쿡 atoi()�� ���� �κ��� �ƴ� ���� ���� ������ �� ���� ���ڵ鸸 ��ȯ�Ѵ�.
		  ���� �κ��� ���� ���ڿ��� ���ڷ� �ָ� �� �������ڸ� ���� �ν��� �� ���� 0�� �����Ѵ�.
		  
*/
int main(void)
{
	int argc = 2;
	char* argv[2];
	int times;

	int n = atoi("asdf");
	printf("%d\n", n);

	argv[0] = "hello";
	argv[1] = "3";
	
	if (argc < 2 || (times = atoi(argv[1])) < 1)
	{
		printf("����: %s �����\n", argv[0]);
	}
	else
	{
		for (int i = 0; i < times; i++)
			puts("�ȳ�, ���� ���� ���̴µ�!");
	}
	
	return 0;
}