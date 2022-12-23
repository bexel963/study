// _Generic은 c11부터 지원된다.

#include <stdio.h>

#define MYTYPE(X) _Generic(X, int: "int", float: "float", double: "double", default: "other");

int main(void)
{
	int d = 5;
										// <출력>
	printf("%s\n", MYTYPE(d));			//  int
	printf("%s\n", MYTYPE(d * 2.0));	//  double
	printf("%s\n", MYTYPE(3L));			//  other
	printf("%s\n", MYTYPE(&d));			//  other

	return 0;
}