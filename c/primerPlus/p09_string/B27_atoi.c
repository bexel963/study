#include <stdio.h>
#include <stdlib.h>


/*
	- 수는 문자열 형태로 또는 수치 형태로 저장할 수 있다.
	  화면에 수를 표시할 때는, 문자로 표시해야 하므로 문자열 형태를 요구한다.

	- atoi()
		: 문자열이 정수로 시작되는 문자열이면 atoi()는 동작한다.
		  그런 경우에 atoi()는 정수 부분이 아닌 것을 만날 때까지 그 앞의 문자들만 반환한다.
		  정수 부분이 없는 문자열을 인자로 주면 그 전달인자를 수로 인식할 수 없고 0을 리턴한다.
		  
*/
int main(void)
{
	int argc = 2;
	char* argv[2];
	int times;

	int n = atoi("asdf");
	printf("%d\n", n);

	argv[0] = "hello";
	argv[1] = "3";
	
	if (argc < 2 || (times = atoi(argv[1])) < 1)
	{
		printf("사용법: %s 양수값\n", argv[0]);
	}
	else
	{
		for (int i = 0; i < times; i++)
			puts("안녕, 얼굴이 좋아 보이는데!");
	}
	
	return 0;
}