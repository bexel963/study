#include <stdio.h>

int main(void)
{
	char side_a[] = "Side A";
	char dont[] = { 'W', '0', 'W', '!' };
	char side_b[] = "Side B";

	/*
		- dont�� ���� �� ���ڰ� ���� ������ ���ڿ��� �ƴϴ�.
		  �׷��� puts()�� ��𿡼� ���߾�� �ϴ��� ���� ���Ѵ�.
		  �׷��� ��򰡿� �ִ� �� ���ڸ� ���� ������ dont���� �����ؼ� �� ���� �޸� ������ ��� ����Ѵ�.
	*/
	puts(dont);

	return 0;
}