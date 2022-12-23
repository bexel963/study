#include <stdio.h>


#define MSG "I am symbolic string constant."	
#define MAXLENGTH 81

// 문자열을 정의하는 방법. - 1.문자열 상수, 2.char형 배열, 3.문자열 배열, 4.char형 포인터
int main(void)
{
	char arr[MAXLENGTH] = {
		'I', ' ', 'a', 'm', ' ', 'a', ' ', 's', 't', 'r', 'i', 'n', 'g', ' ', 'i', 'n', ' ', 'a', 'n',
		' ', 'a', 'r', 'r', 'a', 'y', '\0' 
	};

	/*
		- 문자열 배열
			: 문자열 배열은 char형 배열 초기화 표준 형식을 줄인 것이다.
			  배열의 크기를 지정할 때, 원소들의 개수는 문자열의 길이보다 최소한 하나 더 커야 한다. ('\0' 때매)
			  사용되지 않는 원소들은 모두 숫자 0이 아니라 char형 널 문자('\0')로 자동으로 초기화 된다.
			  다른 배열 이름과 마찬가지로, 문자 배열의 이름은 배열의 첫 번째 원소의 주소를 나타낸다.
	*/
	char words[MAXLENGTH] = "I am a string in an array";	

	const char* ptr1 = "Something is pointing at me.";		// 정적 메모리에 저장된 문자열 상수
	const char ptr2[] = "Something is pointing at me.";		// ptr2 배열에 저장된 문자열

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