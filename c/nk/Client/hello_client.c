#include <stdio.h>
#include <stdlib.h>
#include <winSock2.h>
#pragma comment(lib, "ws2_32.lib")

void ErrorHandling(char* message);

int main()
{
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;

	char message[30];
	int strLen = 0, readLen = 0, idx = 0;
	char ipAddress[] = "127.0.0.1";
	char port[] = "9190";

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		ErrorHandling("WSAStartup() error!");
	}
	else {
		printf("소켓 버전 정보 등록.\n");
	}

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET) {
		ErrorHandling("hSocket() error!");
	}
	else {
		printf("소켓 생성.\n");
	}

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(ipAddress);
	servAddr.sin_port = htons(atoi(port));

	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
		ErrorHandling("connect() error!");
	}
	else {
		printf("연결 요청");
	}

	/*
		strLen = recv(hSocket, message, sizeof(message) - 1, 0);
		if (strLen == -1) {
			ErrorHandling("read() error!");
		}
	*/
	while (readLen = recv(hSocket, &message[idx++], 1, 0)) {
		if (readLen == -1) {
			ErrorHandling("read() error!\n");
			break;
		}
		strLen += readLen;
	}
	printf("Message from server: %s \n", message);
	printf("Function read call count: %d \n", strLen);

	closesocket(hSocket);
	WSACleanup();
	return 0;
}

void ErrorHandling(char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}