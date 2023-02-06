/*
	- 커널 오브젝트에는 해당 리소스의 성격에 따라서 많은 정보가 담긴다.
	  그 중에서도 프로그램의 구현에 있어서 특히 더 관심을 둬야 하는 정보에 대해 '상태'라는 것을 부여한다.

	- 예를들어, 쓰레드의 커널 오브젝트에 있어서의 큰 관심사는 종료 여부이다.
	  때문에, 종료된 상태를 가리켜 'signaled' 상태라 하고, 종료되지 않은 상태를 가리켜 'non_signaled' 상태라 한다.

	- 운영체제는 이 프로세스가 언제 종료되는지, 이 쓰레드는 언제 종료되는지와 같은 관심사에 대한 정보를 커널 오브젝트에 기록해 둔다.
	  그리고 우리에게 '프로세스나 쓰레드가 종료되면 해당 커널 오브젝트를 signaled 상태로 변경해 놓겠다!' 라고 약속하고 있다.

	- 운영체제가 설정한 해당 커널 오브젝트의 상태가 'signaled' 인지 확인하기 위해 WaitForSingleObject, WaitForMultipleObjects 함수를 사용한다.

	- DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
	- DWORD WaitForMultipleObject(DWORD nCount, const HANDLE* lpHandles, BOOL bWaitAll, DWORD dMilliseconds);

	- 위 두 함수는 인자로 INFINITE 전달 시, 커널 오브젝트가 signaled 상태가 되기 전에는 반환하지 않는다.

	- Mutex는 소유되었을 때 non-signaled 상태가 되고, 반납되었을 때 signaled 상태가 되는 커널 오브젝트이다.
	  따라서 Mutex의 소유여부를 확인할 때에는 WaitForSingleObject 함수를 이용할 수 있다.
		- 호출 후 블로킹 상태: Mutex 오브젝트가 다른 쓰레드에게 소유되어서 현재 non-signaled 상태에 놓여있는 상황.
		- 호출 후 반환된 상태: Mutex 오브젝트의 소유가 해제되었거나 소유되지 않아서 signaled 상태에 놓여있는 상황.
		
	- Mutex는 WaitForSingleObject 함수가 반환될 때, 자동으로 non-signaled 상태가 되는 'auto-reset모드' 커널 오브젝트이다.
	  따라서 WaitForSingleObject 함수가 결과적으로 Mutex를 소유할 때 호출하는 함수가 된다.
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
	WaitForSingleObject(hMutex, INFINITE); // Mutex 오브젝트는 이 함수를 호출한 쓰레드의 소유가 된다.
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