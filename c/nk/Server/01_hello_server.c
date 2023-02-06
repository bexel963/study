#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

void ErrorHandling(char* message);

int main() {

	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAddr, clntAddr;

	int szClntAddr;
	char message[] = "�������� �����ϴ� �޽���!!!";
	char port[] = "9190";

	puts("==����==");
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		ErrorHandling("WSAStartup() error!");
	}
	else {
		printf("���� ���� ���� ���...\n");
	}

	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET) {
		ErrorHandling("socket() error!");
	}
	else {
		printf("���� ����...\n");
	}

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(atoi(port));

	if (bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
		ErrorHandling("bind() error!");
	}
	else {
		printf("���� �ּ� ���...\n");
	}

	if (listen(hServSock, 5) == SOCKET_ERROR) {
		ErrorHandling("listen() error!");
	}
	else {
		printf("���� ��û ���...\n");
	}

	szClntAddr = sizeof(clntAddr);
	hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);
	if (hClntSock == INVALID_SOCKET) {
		ErrorHandling("accept() error!");
	}
	else {
		printf("���� ��û ����...\n");
	}

	send(hClntSock, message, sizeof(message), 0);

	closesocket(hClntSock);
	closesocket(hServSock);
	WSACleanup();
	
	getch();

	return 0;
}

void ErrorHandling(char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}