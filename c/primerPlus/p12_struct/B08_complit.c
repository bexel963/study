#include <stdio.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	struct book readfirst;
	int score;
	
	puts("테스트 스코어를 입력하시오: ");
	scanf("%d", &score);

	if (score >= 84)
		readfirst = (struct book){ "Crime and Punishment",
								   "Fyodor Dostoyevsky",
								   11.25 };
	else
		readfirst = (struct book){ "Mr. Bouncy's Nice Hat",
								   "Fred Winsome",
								   5.99 };
	
	printf("할당된 독서:\n");
	printf("%s by %s: $%.2f\n", readfirst.title, readfirst.author, readfirst.value);

	return 0;
}