/*
	- Ŀ�� ������Ʈ���� �ش� ���ҽ��� ���ݿ� ���� ���� ������ ����.
	  �� �߿����� ���α׷��� ������ �־ Ư�� �� ������ �־� �ϴ� ������ ���� '����'��� ���� �ο��Ѵ�.

	- �������, �������� Ŀ�� ������Ʈ�� �־�� ū ���ɻ�� ���� �����̴�.
	  ������, ����� ���¸� ������ 'signaled' ���¶� �ϰ�, ������� ���� ���¸� ������ 'non_signaled' ���¶� �Ѵ�.

	- �ü���� �� ���μ����� ���� ����Ǵ���, �� ������� ���� ����Ǵ����� ���� ���ɻ翡 ���� ������ Ŀ�� ������Ʈ�� ����� �д�.
	  �׸��� �츮���� '���μ����� �����尡 ����Ǹ� �ش� Ŀ�� ������Ʈ�� signaled ���·� ������ ���ڴ�!' ��� ����ϰ� �ִ�.

	- �ü���� ������ �ش� Ŀ�� ������Ʈ�� ���°� 'signaled' ���� Ȯ���ϱ� ���� WaitForSingleObject, WaitForMultipleObjects �Լ��� ����Ѵ�.

	- DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
	- DWORD WaitForMultipleObject(DWORD nCount, const HANDLE* lpHandles, BOOL bWaitAll, DWORD dMilliseconds);

	- �� �� �Լ��� ���ڷ� INFINITE ���� ��, Ŀ�� ������Ʈ�� signaled ���°� �Ǳ� ������ ��ȯ���� �ʴ´�.

	- Mutex�� �����Ǿ��� �� non-signaled ���°� �ǰ�, �ݳ��Ǿ��� �� signaled ���°� �Ǵ� Ŀ�� ������Ʈ�̴�.
	  ���� Mutex�� �������θ� Ȯ���� ������ WaitForSingleObject �Լ��� �̿��� �� �ִ�.
		- ȣ�� �� ���ŷ ����: Mutex ������Ʈ�� �ٸ� �����忡�� �����Ǿ ���� non-signaled ���¿� �����ִ� ��Ȳ.
		- ȣ�� �� ��ȯ�� ����: Mutex ������Ʈ�� ������ �����Ǿ��ų� �������� �ʾƼ� signaled ���¿� �����ִ� ��Ȳ.
		
	- Mutex�� WaitForSingleObject �Լ��� ��ȯ�� ��, �ڵ����� non-signaled ���°� �Ǵ� 'auto-reset���' Ŀ�� ������Ʈ�̴�.
	  ���� WaitForSingleObject �Լ��� ��������� Mutex�� ������ �� ȣ���ϴ� �Լ��� �ȴ�.
*/

#include <stdio.h>
#include <Windows.h>
#include <process.h>

#define NUM_THREAD 50
unsigned WINAPI threadInc(void*);
unsigned WINAPI threadDes(void*);

long long num = 0;
HANDLE hMutex;

int main(void)
{
	HANDLE tHandles[NUM_THREAD];
	int i;

	hMutex = CreateMutex(NULL, FALSE, NULL);

	for (i = 0; i < NUM_THREAD; i++)
	{
		if (i % 2)
			tHandles[i] = (HANDLE)_beginthreadex(NULL, 0, threadInc, NULL, 0, NULL);
		else
			tHandles[i] = (HANDLE)_beginthreadex(NULL, 0, threadDes, NULL, 0, NULL);
	}
	WaitForMultipleObjects(NUM_THREAD, tHandles, TRUE, INFINITE);

	CloseHandle(hMutex);
	printf("result: %lld\n", num);

	return 0;
}

unsigned WINAPI threadInc(void* arg)
{
	int i;
	WaitForSingleObject(hMutex, INFINITE); // Mutex ������Ʈ�� �� �Լ��� ȣ���� �������� ������ �ȴ�.
	for (i = 0; i < 50000000; i++)
		num += 1;
	ReleaseMutex(hMutex);

	return 0;
}

unsigned WINAPI threadDes(void* arg)
{
	int i;
	WaitForSingleObject(hMutex, INFINITE);
	for (i = 0; i < 50000000; i++)
		num -= 1;
	ReleaseMutex(hMutex);

	return 0;
}