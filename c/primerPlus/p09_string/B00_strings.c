#include <stdio.h>


#define MSG "I am symbolic string constant."	
#define MAXLENGTH 81

// ���ڿ��� �����ϴ� ���. - 1.���ڿ� ���, 2.char�� �迭, 3.���ڿ� �迭, 4.char�� ������
int main(void)
{
	char arr[MAXLENGTH] = {
		'I', ' ', 'a', 'm', ' ', 'a', ' ', 's', 't', 'r', 'i', 'n', 'g', ' ', 'i', 'n', ' ', 'a', 'n',
		' ', 'a', 'r', 'r', 'a', 'y', '\0' 
	};

	/*
		- ���ڿ� �迭
			: ���ڿ� �迭�� char�� �迭 �ʱ�ȭ ǥ�� ������ ���� ���̴�.
			  �迭�� ũ�⸦ ������ ��, ���ҵ��� ������ ���ڿ��� ���̺��� �ּ��� �ϳ� �� Ŀ�� �Ѵ�. ('\0' ����)
			  ������ �ʴ� ���ҵ��� ��� ���� 0�� �ƴ϶� char�� �� ����('\0')�� �ڵ����� �ʱ�ȭ �ȴ�.
			  �ٸ� �迭 �̸��� ����������, ���� �迭�� �̸��� �迭�� ù ��° ������ �ּҸ� ��Ÿ����.
	*/
	char words[MAXLENGTH] = "I am a string in an array";	

	const char* ptr1 = "Something is pointing at me.";		// ���� �޸𸮿� ����� ���ڿ� ���
	const char ptr2[] = "Something is pointing at me.";		// ptr2 �迭�� ����� ���ڿ�

	puts("Here are som stings:");

	puts(MSG);
	putchar('\n');
	puts(arr);
	putchar('\n');
	puts(words);
	putchar('\n');

	puts(ptr1);
	putchar('\n');
	puts(ptr2);
	putchar('\n');
	words[8] = 'p';
	puts(words);

	return 0;
}