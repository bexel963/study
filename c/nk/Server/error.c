#include <stdio.h>
#include "myError.h"

void Error(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}