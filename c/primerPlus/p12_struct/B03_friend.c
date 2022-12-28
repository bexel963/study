#include <stdio.h>
#define LEN 20

struct names {
	char first[LEN];
	char last[LEN];
};
struct guy {
	struct names handle;
	char favfood[LEN];
	char job[LEN];
	float income;
};

/*
	- ����ü�� ����Ű�� ������
		: struct guy* him;		// ����ü guy�� ����Ű�� ������ him ����
		  struct guy barney;	// ����ü guy�� ���� barney ����
		  him = &barney;

		  him->income = 100;
		  barney.income = 100;	// �� �ڵ�� ����
		
		: �迭�� ���ʹ� �޸�, ����ü�� �̸��� ����ü�� �ּҰ� �ƴϴ�. �׷��Ƿ� &�����ڸ� ����ؾ� �Ѵ�.
		: fellow�� ����ü�� �迭�̴�. �̰��� fellow[0]�� ����ü��°��� �ǹ��Ѵ�.
		  �׷��� him�� fellow[0]�� ����Ű���� �ʱ�ȭ �Ϸ��� �Ʒ� �ڵ� ó�� �ؾ��Ѵ�.
				him = &fellow[0];

				him->income = 100;
				fellow[0].income = 100;	// ��, �Ʒ� �ڵ�� ����
				(*him).income = 100;	// .�����ڰ� *�����ں��� �켱������ ���� ������ ��ȣ�� �ʿ��ϴ�.

		: �Ϻ� �ý��ۿ��� ����ü�� ũ�Ⱑ �κе��� �պ��� Ŭ �� �ִ�. �̰��� �ý����� �����͸� ��ġ�ϴ� Ư�� ������ �κе� ���̿� ƴ�� ����� �����̴�.
*/
int main(void)
{
	struct guy fellow[2] = {
		{
			{"Ewen", "Villard"},
			"grilled salmon",
			"personality coach",
			681112.00
		},
		{
			{"Rodney", "Swillbelly"},
			"tripe",
			"tabloid editor",
			23240.00
		}
	};
	
	struct guy* him;

	printf("��  �� #1: %p #2: %p\n", &fellow[0], &fellow[1]);
	printf("��  �� #1: %p #2: %p\n", fellow, &fellow[1]);
	him = &fellow[0];
	printf("������ #1: %p #2: %p\n", him, him + 1);

	printf("him->income�� $%.2f, (*him).income�� $%.2f\n", him->income, (*him).income);
	him++;
	printf("him->favfood�� %s, him->handle.last�� %s\n", him->favfood, him->handle.last);

	return 0;
}