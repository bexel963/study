#include <stdio.h>
#include <Windows.h>
#include <process.h>

#define NUM_THREAD 50
unsigned WINAPI threadInc(void*);
unsigned WINAPI threadDes(void*);

long long num = 0;
CRITICAL_SECTION cs;

int main(void)
{
	HANDLE tHandles[NUM_THREAD];
	int i;

	InitializeCriticalSection(&cs);
	for (i = 0; i < NUM_THREAD; i++)
	{
		if (i % 2)
			tHandles[i] = (HANDLE)_beginthreadex(NULL, 0, threadInc, NULL, 0, NULL);
		else
			tHandles[i] = (HANDLE)_beginthreadex(NULL, 0, threadDes, NULL, 0, NULL);
	}
	WaitForMultipleObjects(NUM_THREAD, tHandles, TRUE, INFINITE);
	DeleteCriticalSection(&cs);
	printf("result: %lld\n", num);

	return 0;
}

unsigned WINAPI threadInc(void* arg)
{
	int i;
	EnterCriticalSection(&cs);
	for (i = 0; i < 50000000; i++)
		num += 1;
	LeaveCriticalSection(&cs);

	return 0;
}

unsigned WINAPI threadDes(void* arg)
{
	int i;
	EnterCriticalSection(&cs);
	for (i = 0; i < 50000000; i++)
		num -= 1;
	LeaveCriticalSection(&cs);

	return 0;
}