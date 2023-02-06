#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>
#include "myError.h"

void ShowSocketBufSize(SOCKET sock);

int main(void)
{
	WSADATA wsaData;
	SOCKET hSock;
	int sndBuf, rcvBuf, state;
	
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		Error("WSAStartup() error!!");

	hSock = socket(PF_INET, SOCK_STREAM, 0);
	ShowSocketBufSize(hSock);

	sndBuf = 1024 * 3;
	rcvBuf = 1024 * 3;

	state = setsockopt(hSock, SOL_SOCKET, SO_SNDBUF, (char*)&sndBuf, sizeof(sndBuf));
	if (state == SOCKET_ERROR)
		Error("setsockopt() error!!");

	state = setsockopt(hSock, SOL_SOCKET, SO_RCVBUF, (char*)&rcvBuf, sizeof(rcvBuf));
	if (state == SOCKET_ERROR)
		Error("setsockopt() error!!");

	ShowSocketBufSize(hSock);
	
	closesocket(hSock);
	WSACleanup();

	return 0;
}

void ShowSocketBufSize(SOCKET sock)
{
	int sndBuf, rcvBuf, state, len;

	len = sizeof(sndBuf);
	state = getsockopt(sock, SOL_SOCKET, SO_SNDBUF, (char*)&sndBuf, &len);
	if (state == SOCKET_ERROR)
		Error("getsockopt() error!!");

	len = sizeof(rcvBuf);
	state = getsockopt(sock, SOL_SOCKET, SO_RCVBUF, (char*)&rcvBuf, &len);

	if (state == SOCKET_ERROR)
		Error("getsockopt() error!!");

	printf("Input buffer size: %d\n", rcvBuf);
	printf("Output buffer size: %d\n", sndBuf);
}