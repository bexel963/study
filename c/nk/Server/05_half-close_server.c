#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>
#include "myError.h"

#define BUF_SIZE 30

int main(void)
{
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	FILE* fp;
	char buf[BUF_SIZE];
	int readCnt;

	SOCKADDR_IN servAdr, clntAdr;
	int clntAdrSz;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		Error("WSAStartup() error!!");
	fp = fopen("server.txt", "rb");
	if (fp == NULL)
		puts("���� ���� ����");
	else
		puts("���� ���� ����");

	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET)
		Error("socket() error!!");
	else
		puts("���� ����!!");
	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAdr.sin_port = htons(atoi("8080"));
	
	if (bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr))==SOCKET_ERROR)
		Error("bind() error!!");
	else
		puts("���ε� �Ϸ�!!");

	if (listen(hServSock, 5)==SOCKET_ERROR)
		Error("listen() error!!");
	else
		puts("������ �Ϸ�!!");

	clntAdrSz = sizeof(clntAdr);
	hClntSock = accept(hServSock, (SOCKADDR*)&clntAdr, &clntAdrSz);
	if (hClntSock == INVALID_SOCKET)
		Error("accept() error!!");
	else
		puts("Ŭ���̾�Ʈ�� ��û ����!!");

	while (1)
	{
		readCnt = fread((void*)&buf, 1, BUF_SIZE, fp);
		if (readCnt < BUF_SIZE)
		{
			send(hClntSock, (char*)&buf, readCnt, 0);
			break;
		}
		send(hClntSock, (char*)&buf, BUF_SIZE, 0);
	}
	puts("���� ���� �Ϸ�!!");
	shutdown(hClntSock, SD_SEND);
	recv(hClntSock, (char*)buf, BUF_SIZE, 0);
	printf("Message from client: %s \n", buf);

	fclose(fp);
	WSACleanup();

	getch();

	return 0;
}