#include <stdio.h>
#include <string.h>
#include "myString.h"

#define SIZE 30
#define BUGSIZE 13

/*
	- strcat()�� �� ��° ���ڿ��� ù ��° �迭�� �´��� �˻����� �ʴ´�.
	  ù ��° �迭�� ������ ����� �Ҵ����� �ʴ´ٸ�, �迭�� ä��� ���� ������ ���ڵ��� ������ �޸� ��ġ�� �귯��ġ�� ���°� �Ͼ �� �ִ�.
*/
int main(void)
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes.";
	char bug[BUGSIZE];
	int available;

	// 1. strcat()�� ����ϱ� ���� �� �迭 ������ ���� ���Ѵ�.
	//    �� ���ڸ� ���� ������ �����ϱ� ���� ���յ� ���̿� 1�� ���Ѵ�.
	puts("�װ� ���� �����ϴ� ���� ����?");
	s_gets(flower, SIZE);
	if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
	{
		strcat(flower, addon);
	}
	puts(flower);

	// 2. strncat()���.
	//    3��° ���ڷ� ������ ������ �����ϰų� �� ���ڸ� ������ �߰��� �����.
	//    �� ���ڸ� ī��Ʈ�ϱ� ������, bug�迭�� ������ ���ڿ�(�� ���ڴ� ����), �ִ� 13���� �߰��Ǵ� ���ڵ�, ���� �� ���ڸ� ����� ������ �� ������ŭ Ŀ���Ѵ�.
	puts("�װ� ���� �����ϴ� ������ ����?");
	s_gets(bug, BUGSIZE);
	available = BUGSIZE - strlen(bug) - 1;
	strncat(bug, addon, available);
	puts(bug);

	return 0;
}
