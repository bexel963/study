#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film {
	char title[TSIZE];
	int rating;
	struct film* next;
};

char* s_gets(char* st, int n);

int main(void)
{
	struct film* head = NULL;
	struct film* prev = NULL, * current = NULL, * rear = NULL;
	char input[TSIZE];

	puts("ù ��° ��ȭ Ÿ��Ʋ�� �Է��Ͻÿ�:");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film*)malloc(sizeof(struct film));
		if (head == NULL)
			head = current;
		else
		{
			prev->next = current;
		}			
		current->next = NULL;
		strcpy(current->title, input);
		puts("�򰡸� �Է��Ͻÿ�(0������ 10������) :");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("���� ��ȭ Ÿ��Ʋ�� �Է��Ͻÿ�(�������� �� ����):");
		prev = current;
	}
	if (head == NULL)
		puts("�Էµ� �����Ͱ� �����ϴ�.");
	else
		puts("��ȭ���� ����� ������ �����ϴ�.");

	current = head;
	while (current != NULL)
	{		
		printf("����: %s   ��: %d\n", current->title, current->rating);
		current = current->next;
	}

	current = head;
	while (current != NULL)
	{
		free(current);
		current = current->next;
	}
	puts("��!");

	return 0;
}

char* s_gets(char* st, int n)
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