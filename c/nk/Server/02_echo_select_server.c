#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>
#include "myError.h"

#define BUF_SIZE 1024

int main(void)
{
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAdr, clntAdr;
	TIMEVAL timeout;
	fd_set reads, cpyReads;

	int adrSz;
	int strLen, fdNum, i;
	char buf[BUF_SIZE];

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		Error("WSAStartup() error!!");
	else
		puts("소켓 버전 정보 설정.");

	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == SOCKET_ERROR)
		Error("socket() error");
	else
		printf("서버 소켓 생성. %d\n", hServSock);

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAdr.sin_port = htons(atoi("9190"));

	if (bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		Error("bind() error");
	else
		puts("서버 소켓 주소 할당.");

	if (listen(hServSock, 5) == SOCKET_ERROR)
		Error("listen() error");
	else
		puts("연결 요청 대기중....");

	FD_ZERO(&reads);
	FD_SET(hServSock, &reads);
	printf("fd_count: %d\n", reads.fd_count);
	fputs("fd_array: ", stdout);
	for (int j = 0; j < 64; j++)
	{
		printf("%u ", reads.fd_array[j]);
	}
	putchar('\n');

	while (1)
	{
		cpyReads = reads;
		timeout.tv_sec = 5;
		timeout.tv_usec = 5000;

		if ((fdNum = select(0, &cpyReads, 0, 0, &timeout)) == SOCKET_ERROR)
			break;
		else
			printf("%d개의 소켓이 감지됨.\n", fdNum);

		if (fdNum == 0)
			continue;
		
		for (i = 0; i < reads.fd_count; i++)
		{
			if (FD_ISSET(reads.fd_array[i], &cpyReads))
			{
				if (reads.fd_array[i] == hServSock)
				{
					adrSz = sizeof(clntAdr);
					hClntSock = accept(hServSock, (SOCKADDR*)&clntAdr, &adrSz);
					FD_SET(hClntSock, &reads);
					fputs("fd_array: ", stdout);
					for (int j = 0; j < 64; j++)
					{
						printf("%u ", reads.fd_array[j]);
					}
					putchar('\n');
					printf("connected client: %d\n", hClntSock);
				}
				else
				{
					strLen = recv(reads.fd_array[i], buf, BUF_SIZE - 1, 0);
					if (strLen == 0)
					{
						FD_CLR(reads.fd_array[i], &reads);
						closesocket(cpyReads.fd_array[i]);
						printf("closed client: %d\n", cpyReads.fd_array[i]);
					}
					else
					{
						send(reads.fd_array[i], buf, strLen, 0);
					}
				}
			}
		}
	}
	closesocket(hServSock);
	WSACleanup();

	return 0;
}