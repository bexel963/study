/*
	- 문제점
		: send(), recv() 가 호출될 때마다 문자열 단위로 실제 입출력이 이뤄진다.
		  하지만 TCP는 데이터의 경계가 존재하지 않는다.
		  즉, 둘 이상의 send()호출로 전달된 문자열 정보가 묶여서 한번에 서버로 전송될 수 있다.
		  그리고 그러한 상황이 발생하면 클라이언트는 한번에 둘 이상의 문자열 정보를 서버로부터 되돌려 받아서, 원하는 결과를 얻지 못할 수 있다.

		  또 다른 경우로, 서버는 한번의 send()호출로 데이터 전송을 명령했지만, 전송할 데이터의 크기가 크다면 OS는 내부적으로 이를 여러 개의 
		  조각으로 나눠서 클라이언트에게 전송할 수도 있는 일이다.
		  그리고 이 과정에서 데이터의 모든 조각이 클라이언트에게 전송되지 않았음에도 불구하고, 클라이언트는 read함수를 호출할지도 모른다.
		  이 모든 문제가 TCP의 데이터 전송특성에서 비롯된 것이다.
*/
#include <stdio.h>
#include <winsock2.h>
#include <stdlib.h>
#include <string.h>
#pragma comment(lib, "ws2_32.lib")

#define BUF_SIZE 1024
void ErrorHandling(char* message);

void main()
{
	printf("----클라이언트----\n");
	WSADATA wsaData;
	SOCKET hSocket;
	char message[BUF_SIZE];
	int strLen;
	SOCKADDR_IN servAdr;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) ErrorHandling("WSAStartup() error!");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET) ErrorHandling("socket() error!");
	
	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAdr.sin_port = htons(atoi("9190"));

	if (connect(hSocket, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		ErrorHandling("connect() error!");
	else
		puts("\nConnected.............");

	while (1)
	{
		fputs("\nInput message(Q to quit): ", stdout);
		fgets(message, BUF_SIZE, stdin);

		if (!strcmp(message, "q\n") || !strcmp(message, "Q\n")) break;

		send(hSocket, message, strlen(message), 0);
		strLen = recv(hSocket, message, BUF_SIZE - 1, 0);
		message[strLen] = 0;
		printf("Message from server: %s \n", message);
	}
	closesocket(hSocket);
	WSACleanup();
}

void ErrorHandling(char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}