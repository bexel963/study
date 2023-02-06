/*
	- 서버는 한 순간에 하나의 클라이언트와 연결되어 에코 서비스를 제공한다.
	- 서버는 총 다섯 개의 클라이언트에게 순차적으로 서비스를 제공하고 종료한다.
	- 클라이언트는 프로그램 사용자로부터 문자열 데이터를 입력 받아서 서버에 전송한다.
	- 서버는 전송 받은 문자열 데이터를 클라이언트에게 재전송한다. 즉, 에코시킨다.
	- 서버와 클라이언트간의 문자열 에코는 클라이언트가 Q를 입력할 때까지 계속한다.
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

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) ErrorHandling("버전 등록 중 에러...");
	
	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET) ErrorHandling("소켓 생성 에러..");

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAdr.sin_port = htons(atoi("9190"));

	if (bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR) ErrorHandling("바인딩 중 에러...");

	if (listen(hServSock, 5) == SOCKET_ERROR) ErrorHandling("리스닝 에러...");
	
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