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

	puts("==Ŭ���̾�Ʈ==");
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		ErrorHandling("WSAStartup() error!");
	}
	else {
		printf("���� ���� ���� ���.\n");
	}

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET) {
		ErrorHandling("hSocket() error!");
	}
	else {
		printf("���� ����.\n");
	}

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(ipAddress);
	servAddr.sin_port = htons(atoi(port));

	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
		ErrorHandling("connect() error!");
	}
	else {
		printf("���� ��û\n");
	}

	/*
		strLen = recv(hSocket, message, sizeof(message) - ��1, 0);
		if (strLen == -1) {
			ErrorHandling("read() error!");
		}
	*/
	while (readLen = recv(hSocket, &message[idx++], 1, 0)) {	// <- ������������ ���۵Ǵ� �������� ��谡 �������� �ʴٴ°��� Ȯ��
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

	getch();

	return 0;
}

void ErrorHandling(char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}