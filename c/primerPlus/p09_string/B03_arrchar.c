#include <stdio.h>
#define SLEN 40
#define LIM 5

int main(void)
{
	/*
		- �迭�� ������
			0. �迭 �̸� heart�� ���������, ������ head�� �����̴�.
			1. �� �� �迭 ǥ�⸦ ����� �� �ִ�.
			2. �� �� ������ ������ ����� �� �ִ�.
			3. ������ ���ĸ� ���� �����ڸ� ����� �� �ִ�.
			4. �迭�� �̸��� ��� ������, �迭�� ���ҵ��� �����̴�.

		- head[0] = 'A';	-> Error
			: ������ ���ڿ� ���ͷ����� �޸𸮿� ���Ϻ����� ��Ÿ���� ���� �����Ϸ��� ������ �� �ִ�.
			  �����Ϸ��� �̿� ���� ���Ϻ� ǥ�� ����� ����ϰ�, head[0]�� "A"�� �����ϴ� ���� ����Ѵٸ� �� ���ڿ��� ���� ��� ���� ������ �޴´�.
			  �׷��Ƿ� �����͸� ���ڿ� ���ͷ��� �ʱ�Ȱ�� ��, const �����ڸ� ����ϴ� ���� �ٶ����ϴ�.

		- ���ڿ��� �ٲ� ��ȹ�� �ִٸ� ���ڿ� ���ͷ��� �����͸� ������� �ʴ´�.
	*/
	char heart[] = "I love Tillie!";
	const char* head = "I love Millie!";
	

	for (int i = 0; i < 6; i++)
		putchar(heart[i]);
	putchar('\n');
	for (int i = 0; i < 6; i++)
		putchar(head[i]);
	putchar('\n');
	
	for (int i = 0; i < 6; i++)
		putchar(*(heart + i));
	putchar('\n');
	for (int i = 0; i < 6; i++)
		putchar(*(head + i));
	putchar('\n');

	while (*(head) != '\0')
		putchar(*(head++));
	putchar('\n');
	
	puts("\n=============================================================\n");

	/*
		- mytalents
			: 5���� ������ �迭
			  mytalents ���� �����ʹ� �ʱ�ȭ�� ���� ���ڿ� ���ͷ��� ��ġ�� ����Ű�µ�, �̰�(���ͷ�)�� ������ �޸𸮿� ����ȴ�.
			  mytalents�� �� ���� ���̴� ���߳����̴�(���� ���̰� ���� �ٸ���).
			  ������ mytalents �迭 ���ҿ� ���� ���������� ���ڿ��� �޸𸮿�  �ݵ�� ���������� ����� �ʿ�� ����.
			  mytalents ���� �����͵��� ���ڿ� ���ͷ��� ����Ű�� ������ �� ���ڿ��� ��ĥ �� ����.

		- yourtalents
			: �� SLENũ���� ���� ���� �迭 5���� �迭
			  yourtalents���� �迭�� ���ڿ� ���ͷ��� ���纻�� ���ԵǾ��� ������ �� ���ڿ��� �� ���� ����ȴ�.
			  yourtalents�� �� ���Ҵ� ���� ũ���̸�, ũ�Ⱑ ���� �� ���ڿ��� ������ �� �ֵ��� ũ�Ⱑ ����ؾ� �ϱ� ������ �迭���� �޸� �Ҵ��� ��ȿ�����̴�.
			  yourtalents�� ������� �ٲ� �� �ִ�.

		- ���ڿ��� ��ġ�ų� ���ڿ� �Է��� ���� ������ Ȯ���ϱ⸦ ���Ѵٸ� ���ڿ� ���ͷ��� ����Ű�� �����͸� ������� �ʴ´�.
	*/
	const char* mytalents[LIM] = {
		"Adding numbers swiftly",
		"Multiplying accurately", "Stashing data",
		"Following instructions to the letter",
		"Understanding the C languate"
	};
	char yourtalents[LIM][SLEN] = {
		"Walking in a straight line",
		"Sleeping", "Watching television",
		"Mailing letters", "Reading email"
	};

	int i;
	
	puts("Let's compare talents.");
	printf("%-36s %-30s\n", "My Talents", "Your Talents");
	for (i = 0; i < LIM; i++)
	{
		printf("%-36s %-30s\n", mytalents[i], yourtalents[i]);
	}
	printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n", sizeof(mytalents), sizeof(yourtalents));

	return 0;
}