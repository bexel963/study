// �������̽� ����ϱ� - ADT ��Ÿ���� ��ũ�� ����Ʈ�� ����Ѵ�.

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
void showmovies(Item item);
char* s_gets(char* st, int n);

int main(void)
{
	List movies;
	Item temp;

	// �ʱ�ȭ
	InitializeList(&movies);
	if (ListIsFull(&movies))
	{
		fprintf(stderr, "����� �� �ִ� �޸𸮰� �����ϴ�! �ȳ�!\n");
		exit(1);
	}

	// �Է°� ����
	puts("ù ��° ��ȭ Ÿ��Ʋ�� �Է��Ͻÿ�:");
	while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
	{
		puts("�򰡸� �Է��Ͻÿ�(0������ 10������):");
		scanf("%d", &temp.rating);
		while (getchar() != '\n');
			continue;
		if (AddItem(temp, &movies) == false)
		{
			fprintf(stderr, "�޸� �Ҵ翡 ���� �߻�\n");
			break;
		}
		if (ListIsFull(&movies))
		{
			puts("����Ʈ�� ���� á���ϴ�.");
			break;
		}
		pust("���� ��ȭ Ÿ��Ʋ�� �Է��Ͻÿ�(�������� �� ����): ");			
	}

	// ���
	if (ListIsEmpty(&movies))
		puts("�Էµ� �����Ͱ� �����ϴ�.\n");
	else
	{
		puts("��ȭ���� ���� ������ �����ϴ�.\n");
		Traverse(&movies, showmovies);
	}
	printf("%d���� ��ȭ�� �Է��߽��ϴ�.\n", ListItemCount(&movies));

	
	// ����Ʈ ����
	EmptyTheList(&movies);
	puts("��!!");
}

void showmovies(Item item)
{
	printf("��ȭ����: %s     ��: %d\n", item.title, item.rating);
}
void* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}