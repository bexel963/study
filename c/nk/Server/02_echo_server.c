/*
	- ������ �� ������ �ϳ��� Ŭ���̾�Ʈ�� ����Ǿ� ���� ���񽺸� �����Ѵ�.
	- ������ �� �ټ� ���� Ŭ���̾�Ʈ���� ���������� ���񽺸� �����ϰ� �����Ѵ�.
	- Ŭ���̾�Ʈ�� ���α׷� ����ڷκ��� ���ڿ� �����͸� �Է� �޾Ƽ� ������ �����Ѵ�.
	- ������ ���� ���� ���ڿ� �����͸� Ŭ���̾�Ʈ���� �������Ѵ�. ��, ���ڽ�Ų��.
	- ������ Ŭ���̾�Ʈ���� ���ڿ� ���ڴ� Ŭ���̾�Ʈ�� Q�� �Է��� ������ ����Ѵ�.
*/
#include <stdio.h>
#include <winsock2.h>
#include <stdlib.h>
#include <string.h>
#pragma comment(lib, "ws2_32.lib")

#define BUF_SIZE 1024
void ErrorHandling(char* message);

void main() {
	
	printf("----server----\n");

	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	char message[BUF_SIZE];
	int strLen, i;

	SOCKADDR_IN servAdr, clntAdr;
	int clntAdrSize;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) ErrorHandling("���� ��� �� ����...");
	
	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET) ErrorHandling("���� ���� ����..");

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAdr.sin_port = htons(atoi("9190"));

	if (bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR) ErrorHandling("���ε� �� ����...");

	if (listen(hServSock, 5) == SOCKET_ERROR) ErrorHandling("������ ����...");
	
	clntAdrSize = sizeof(clntAdr);

	for (i = 0; i < 5; i++) 
	{
		hClntSock = accept(hServSock, (SOCKADDR*)&clntAdr, &clntAdrSize);
		if (hClntSock == -1) 
			ErrorHandling("accept() Error...");
		else 
			printf("\nConnected client %d \n", i + 1);
		
		while ((strLen = recv(hClntSock, message, BUF_SIZE, 0)) != 0)
			send(hClntSock, message, strLen, 0);
		
		closesocket(hClntSock);
	}
	closesocket(hServSock);
	WSACleanup();
}

void ErrorHandling(char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}