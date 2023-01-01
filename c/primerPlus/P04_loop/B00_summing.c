#include <stdio.h>

int main(void)
{
	long num = 0;
	long sum = 0L;
	int status;

	char ch;

	printf("합을 구할 정수 하나 입력!");
	printf("(끝내려면 q): ");
	
	status = scanf("%ld", &num);	// 만약 여기서 문자를 입력하면 scanf()는 입력을 읽지 않고 해당 문자를 입력 큐로 되돌린다.
	printf("\n\n%d\n", status);	// 읽기에 실패하여 0이 반환된다.
	status = scanf("%c", &ch);		// 되돌려진 문자를 여기서 읽게된다.
	while (status == 1)
	{
		sum += num;
		printf("다음 정수 입력!(끝내려면 q): ");
		status = scanf("%ld", &num);
	}
	printf("입력된 정수들의 합: %ld\n", sum);

	return 0;
}