#include <stdio.h>
#define LEN 100

char* string_in(char*, char*);

int main(void)
{
	char source[LEN] = "abcdaefghijaehyungscxvoisd";
	char item[LEN];
	int i;
	char* result;

	fputs("ã�� ���ڿ��� �Է�(�����Ϸ��� [enter]�Է�): ", stdout);
	while (fgets(item, 10, stdin) != NULL && item[0] != '\n')
	{
		i = 0;
		while (item[i] != '\n' && item[i] != '\0')
		{
			i++;
		}			
		if (item[i] == '\n') {
			item[i] = '\0';
		}			
		else
		{
			while (getchar() != '\n')
				continue;
		}
		
		fputs("ã������ �ϴ� ���ڿ�: ", stdout);
		puts(item);

		result = string_in(source, item);
		
		if (result)
		{
			fputs("ã��!! ã�� ���ڿ� ���� ���: ", stdout);
			puts(result);
		}
		else
			puts("�� ã�� �Ф�");
		fputs("ã�� ���ڿ��� �Է�(�����Ϸ��� [enter]�Է�): ", stdout);
	}
	
	puts("\n����\n");
}

char* string_in(char* source, char* item)
{
	// item�� ù ���ڰ� source�� ������
		// item�� ������ ��� ���ڵ� source�� ���޾� �ִ��� Ž��
			// ������ item�� ù ������ �ּ� ����
			// ������ �ٽ� item�� ù���ڿ� ��ġ�ϴ� ���ڰ� source�� �ִ��� Ž�� -> �ݺ�...
	char* ps = source;
	char* tmp;
	char* pi = item;
	char* result;
	int find = 0;

	while (*ps != '\0')
	{
		if (*ps == *pi)
		{
			tmp = ps;
			find = 1;
			while (*pi != '\0')
			{
				if (*(ps++) != *(pi++))
					find = 0;
			}
			if (find)
				return tmp;
			else
			{
				pi = item;
				ps = tmp;
			}			
		}
		ps++;
	}
	
	if (!find)
	{
		return NULL;
	}
}